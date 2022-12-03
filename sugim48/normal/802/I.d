/+ dub.sdl:
    name "I"
    dependency "dcomp" version=">=0.6.0"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dcomp.foundation, dcomp.scanner;
// import dcomp.array;
// import dcomp.algorithm;
// import dcomp.string;
// import dcomp.datastructure.lazyseg;
// import dcomp.container.deque;

void solve() {
    string s;
    sc.read(s);
    auto saInfo = suffixArray(s);
    int n = s.length.to!int;
    auto tr = LazySeg!(long[2], int, (a, b)=>[a[0]+b[0], a[1]+b[1]].fixed, (a, b)=>[b * a[1], a[1]].fixed, (a, b)=>b, [0L, 1L].fixed, -1)(n);
    tr[0..n] += 10^^9;
    long sm = 0;
    Deque!(int[2]) deq;
    deq.insertBack([-1, 0]);
    foreach (i; 1..n) {
        auto u = saInfo.lcp[i];
        while (deq.back[0] >= u) deq.removeBack;
//        auto le = binSearch!(x => tr.single(x)[0] >= u)(-1, i);
        auto le = deq.back[1];
//        writeln(le, " ", le2, " ", deq);
        tr[le..i] += u;
        sm += tr[0..i].sum[0];
        deq.insertBack([u, i]);
//        writeln(tr);
    }
    writeln(sm*2 + long(n)*(n+1)/2);
}


int main() {
    int n;
    sc.read(n);
    foreach (i; 0..n) {
        solve();
    }
    return 0;
}

Scanner sc;
static this() {
    sc = new Scanner(stdin);
}
/* IMPORT /Users/yosupo/Program/dcomp/source/dcomp/container/deque.d */
// module dcomp.container.deque;

struct Deque(T, bool mayNull = true) {
    import core.exception : RangeError;
    import core.memory : GC;
    import std.range : ElementType, isInputRange;
    import std.traits : isImplicitlyConvertible;

    struct Payload {
        T *d;
        size_t st, length, cap;
        @property bool empty() const { return length == 0; }
        alias opDollar = length;
        ref inout(T) opIndex(size_t i) inout {
            version(assert) if (length <= i) throw new RangeError();
            return d[(st+i >= cap) ? (st+i-cap) : st+i];
        }
        private void expand() {
            import std.algorithm : max;
            assert(length == cap);
            auto nc = max(size_t(4), 2*cap);
            T* nd = cast(T*)GC.malloc(nc * T.sizeof);
            foreach (i; 0..length) {
                nd[i] = this[i];
            }
            d = nd; st = 0; cap = nc;
        }
        void clear() {
            st = length = 0;
        }
        void insertFront(T v) {
            if (length == cap) expand();
            if (st == 0) st += cap;
            st--; length++;
            this[0] = v; 
        }
        void insertBack(T v) {
            if (length == cap) expand();
            length++;
            this[length-1] = v; 
        }
        void removeFront() {
            assert(!empty, "Deque.removeFront: Deque is empty");        
            st++; length--;
            if (st == cap) st = 0;
        }
        void removeBack() {
            assert(!empty, "Deque.removeBack: Deque is empty");        
            length--;
        }
    }
    struct RangeT(A) {
        alias T = typeof(*(A.p));
        alias E = typeof(A.p.d[0]);
        T *p;
        size_t a, b;
        @property bool empty() const { return b <= a; }
        @property size_t length() const { return b-a; }
        @property RangeT save() { return RangeT(p, a, b); }
        @property RangeT!(const A) save() const {
            return typeof(return)(p, a, b);
        }
        alias opDollar = length;
        @property ref inout(E) front() inout { return (*p)[a]; }
        @property ref inout(E) back() inout { return (*p)[b-1]; }
        void popFront() {
            version(assert) if (empty) throw new RangeError();
            a++;
        }
        void popBack() {
            version(assert) if (empty) throw new RangeError();
            b--;
        }
        ref inout(E) opIndex(size_t i) inout { return (*p)[i]; }
        RangeT opSlice() { return this.save; }
        RangeT opSlice(size_t i, size_t j) {
            version(assert) if (i > j || a + j > b) throw new RangeError();
            return typeof(return)(p, a+i, a+j);
        }
        RangeT!(const A) opSlice() const { return this.save; }
        RangeT!(const A) opSlice(size_t i, size_t j) const {
            version(assert) if (i > j || a + j > b) throw new RangeError();
            return typeof(return)(p, a+i, a+j);
        }
    }
    
    alias Range = RangeT!Deque;
    alias ConstRange = RangeT!(const Deque);
    alias ImmutableRange = RangeT!(immutable Deque);

    Payload* p;
    private void I() { if (mayNull && !p) p = new Payload(); }
    private void C() const {
        version(assert) if (mayNull && !p) throw new RangeError();
    }
    static if (!mayNull) {
        @disable this();
    }
     
    private this(Payload* p) {
        this.p = p;
    }
    this(U)(U[] values...) if (isImplicitlyConvertible!(U, T)) {
        p = new Payload();
        foreach (v; values) {
            insertBack(v);
        }
    }
     
    this(Range)(Range r)
    if (isInputRange!Range &&
    isImplicitlyConvertible!(ElementType!Range, T) &&
    !is(Range == T[])) {
        p = new Payload();
        foreach (v; r) {
            insertBack(v);
        }
    }
    static Deque make() { return Deque(new Payload()); }
    @property bool havePayload() const { return (!mayNull || p); }
    @property bool empty() const { return (!havePayload || p.empty); }
    @property size_t length() const { return (havePayload ? p.length : 0); }
    alias opDollar = length;
    ref inout(T) opIndex(size_t i) inout {C; return (*p)[i]; }
    ref inout(T) front() inout {C; return (*p)[0]; }
    ref inout(T) back() inout {C; return (*p)[$-1]; }
    void clear() { if (p) p.clear(); }
    void insertFront(T v) {I; p.insertFront(v); }
    void insertBack(T v) {I; p.insertBack(v); }
    void removeFront() {C; p.removeFront(); }
    void removeBack() {C; p.removeBack(); }
    Range opSlice() {I; return Range(p, 0, length); }
}

 

 

 

 

 
/* IMPORT /Users/yosupo/Program/dcomp/source/dcomp/array.d */
// module dcomp.array;

 
T[N] fixed(T, size_t N)(T[N] a) {return a;}

 
 

 
 
struct FastAppender(A) {
    import std.algorithm : max;
    import std.range.primitives : ElementEncodingType;
    import core.stdc.string : memcpy;

    private alias T = ElementEncodingType!A;
    private T* _data;
    private size_t len, cap;
     
    @property size_t length() {return len;}
     
    void reserve(size_t nlen) {
        import core.memory : GC;
        if (nlen <= cap) return;
        
        void* nx = GC.malloc(nlen * T.sizeof);

        cap = nlen;
        if (len) memcpy(nx, _data, len * T.sizeof);
        _data = cast(T*)(nx);
    }
     
    void opOpAssign(string op : "~")(T item) {
        if (len == cap) {
            reserve(max(4, cap*2));
        }
        _data[len++] = item;
    }
     
    void clear() {
        len = 0;
    }
     
    T[] data() {
        return (_data) ? _data[0..len] : null;
    }
}

 
/* IMPORT /Users/yosupo/Program/dcomp/source/dcomp/datastructure/lazyseg.d */
// module dcomp.datastructure.lazyseg;

struct LazySeg(T, L, alias opTT, alias opTL, alias opLL, T eT, L eL) {
    const int n, sz, lg;
    T[] d;
    L[] lz;
    @disable this();
    this(int n) {
        import std.algorithm : fill, each;
        import core.bitop : bsr;
        if (n == 0) return;
        int lg = n.bsr;
        if ((2^^lg) < n) lg++;
        this.n = n;
        this.sz = 2^^lg;
        this.lg = lg;
        d = new T[](2*this.sz);
        d.each!((ref x) => x = eT);
        lz = new L[](2*this.sz);
        lz.each!((ref x) => x = eL);
    }
    private void lzAdd(int k, L x) {
        d[k] = opTL(d[k], x);
        lz[k] = opLL(lz[k], x);
    }
    private void push(int k) {
        if (lz[k] == eL) return;
        lzAdd(2*k, lz[k]);
        lzAdd(2*k+1, lz[k]);
        lz[k] = eL;
    }
    T sum(int a, int b, int l, int r, int k) {
        if (b <= l || r <= a) return eT;
        if (a <= l && r <= b) return d[k];
        push(k);
        int md = (l+r)/2;
        return opTT(sum(a, b, l, md, 2*k),
            sum(a, b, md, r, 2*k+1));
    }
    T single(int k) {
        k += sz;
        foreach_reverse (int i; 1..lg+1) {
            push(k>>i);
        }
        return d[k];
    }
    T sum(int a, int b) {
        assert(0 <= a && a <= b && b <= n);
        return sum(a, b, 0, sz, 1);
    }
    void add(int a, int b, L x, int l, int r, int k) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lzAdd(k, x);
            return;
        }
        push(k);
        int md = (l+r)/2;
        add(a, b, x, l, md, 2*k);
        add(a, b, x, md, r, 2*k+1);
        d[k] = opTT(d[2*k], d[2*k+1]);
    }
    void add(int a, int b, L x) {
        assert(0 <= a && a <= b && b <= n);
        add(a, b, x, 0, sz, 1);
    }
    @property int opDollar() const {return sz;}
    struct Range {
        LazySeg* seg;
        int start, end;
        @property T sum() {
            return seg.sum(start, end);
        }
    }
    int[2] opSlice(size_t dim)(int start, int end) {
        assert(0 <= start && start <= end && end <= sz);
        return [start, end];
    }
    Range opIndex(int[2] rng) {
        return Range(&this, rng[0], rng[1]);
    }
    void opIndexOpAssign(string op : "+")(L x, int[2] rng) {
        add(rng[0], rng[1], x);
    }
}
/* IMPORT /Users/yosupo/Program/dcomp/source/dcomp/string.d */
// module dcomp.string;

 
struct SA(T) {
    T[] s;  
     
    int[] sa, rsa, lcp;
    this(in T[] s) {
        size_t n = s.length;
        this.s = s.dup;
        sa = new int[](n+1);
        rsa = new int[](n+1);
        lcp = new int[](n);
    }
}

int[] sais(T)(in T[] _s, int B = 200) {
    import std.conv, std.algorithm, std.range;
    int n = _s.length.to!int;
    int[] sa = new int[](n+1);
    if (n == 0) return sa;

    auto s = _s.map!"a+1".array ~ T(0); B++;  
     
    bool[] ls = new bool[](n+1);
    ls[n] = true;
    foreach_reverse (i; 0..n) {
        ls[i] = (s[i] == s[i+1]) ? ls[i+1] : (s[i] < s[i+1]);
    }
     
    int[] sumL = new int[](B+1), sumS = new int[](B+1);        
    s.each!((i, c) => !ls[i] ? sumS[c]++ : sumL[c+1]++);
    foreach (i; 0..B) {
        sumL[i+1] += sumS[i];
        sumS[i+1] += sumL[i+1];
    }

    void induce(in int[] lms) {
        sa[] = -1;
        auto buf0 = sumS.dup;
        foreach (d; lms) {
            sa[buf0[s[d]]++] = d;
        }
        auto buf1 = sumL.dup;
        foreach (v; sa) {
            if (v >= 1 && !ls[v-1]) {
                sa[buf1[s[v-1]]++] = v-1;
            }
        }
        auto buf2 = sumL.dup;
        foreach_reverse (v; sa) {
            if (v >= 1 && ls[v-1]) {
                sa[--buf2[s[v-1]+1]] = v-1;
            }
        }
    }
    
    int[] lms = iota(1, n+1).filter!(i => !ls[i-1] && ls[i]).array;
    int[] lmsMap = new int[](n+1);
    lmsMap[] = -1; lms.each!((i, v) => lmsMap[v] = i.to!int);

    induce(lms);
    
    if (lms.length >= 2) {
        int m = lms.length.to!int - 1;
         
        auto lms2 = sa.filter!(v => lmsMap[v] != -1).array;
        int recN = 1;
        int[] recS = new int[](m);
        recS[lmsMap[lms2[1]]] = 1;
        foreach (i; 2..m+1) {
            int l = lms2[i-1], r = lms2[i];
            int nl = lms[lmsMap[l]+1], nr = lms[lmsMap[r]+1];
            if (cmp(s[l..nl+1], s[r..nr+1])) recN++;
            recS[lmsMap[lms2[i]]] = recN;
        }
         
        induce(lms.indexed(sais!int(recS, recN)).array);
    }

    return sa;
}


 
SA!T suffixArray(T)(in T[] _s, int B = 200) {
    import std.conv, std.algorithm;
    int n = _s.length.to!int;
    auto saInfo = SA!T(_s);
    if (n == 0) return saInfo;
    
    with (saInfo) {
        sa = sais(_s, B);
         
        sa.each!((i, v) => rsa[v] = i.to!int);
         
        int h = 0;
        foreach (i; 0..n) {
            int j = sa[rsa[i]-1];
            if (h > 0) h--;
            for (; j+h < n && i+h < n; h++) {
                if (s[j+h] != s[i+h]) break;
            }
            lcp[rsa[i]-1] = h;
        }
    }
    return saInfo;
}

 
 

 
/* IMPORT /Users/yosupo/Program/dcomp/source/dcomp/scanner.d */
// module dcomp.scanner;

class Scanner {
    import std.stdio : File;
    import std.conv : to;
    import std.range : front, popFront, array, ElementType;
    import std.array : split;
    import std.traits : isSomeChar, isStaticArray, isArray; 
    import std.algorithm : map;
    File f;
    this(File f) {
        this.f = f;
    }
    char[512] lineBuf;
    char[] line;
    private bool succ() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (true) {
            while (!line.empty && line.front.isWhite) {
                line.popFront;
            }
            if (!line.empty) break;
            if (f.eof) return false;
            line = lineBuf[];
            f.readln(line);
        }
        return true;
    }

    private bool readSingle(T)(ref T x) {
        import std.algorithm : findSplitBefore;
        import std.string : strip;
        import std.conv : parse;
        if (!succ()) return false;
        static if (isArray!T) {
            alias E = ElementType!T;
            static if (isSomeChar!E) {
                 
                 
                auto r = line.findSplitBefore(" ");
                x = r[0].strip.dup;
                line = r[1];
            } else {
                auto buf = line.split.map!(to!E).array;
                static if (isStaticArray!T) {
                     
                    assert(buf.length == T.length);
                }
                x = buf;
                line.length = 0;
            }
        } else {
            x = line.parse!T;
        }
        return true;
    }
    int read(T, Args...)(ref T x, auto ref Args args) {
        if (!readSingle(x)) return 0;
        static if (args.length == 0) {
            return 1;
        } else {
            return 1 + read(args);
        }
    }
}



 

 
/* IMPORT /Users/yosupo/Program/dcomp/source/dcomp/algorithm.d */
// module dcomp.algorithm;

import std.range.primitives;
import std.traits : isFloatingPoint, isIntegral;

 
T binSearch(alias pred, T)(T l, T r) if (isIntegral!T) {
    while (r-l > 1) {
        T md = (l+r)/2;
        if (!pred(md)) l = md;
        else r = md;
    }
    return r;
}

 
T binSearch(alias pred, T)(T l, T r, int cnt = 60) if (isFloatingPoint!T) {
    foreach (i; 0..cnt) {
        T md = (l+r)/2;
        if (!pred(md)) l = md;
        else r = md;
    }
    return r;
}

 
 

 
E minimum(alias pred = "a < b", Range, E = ElementType!Range)(Range range, E seed)
if (isInputRange!Range && !isInfinite!Range) {
    import std.algorithm, std.functional;
    return reduce!((a, b) => binaryFun!pred(a, b) ? a : b)(seed, range);
}

 
ElementType!Range minimum(alias pred = "a < b", Range)(Range range) {
    assert(!range.empty, "range must not empty");
    auto e = range.front; range.popFront;
    return minimum!pred(range, e);
}

 
 

 
E maximum(alias pred = "a < b", Range, E = ElementType!Range)(Range range, E seed)
if (isInputRange!Range && !isInfinite!Range) {
    import std.algorithm, std.functional;
    return reduce!((a, b) => binaryFun!pred(a, b) ? b : a)(seed, range);
}

 
ElementType!Range maximum(alias pred = "a < b", Range)(Range range) {
    assert(!range.empty, "range must not empty");
    auto e = range.front; range.popFront;
    return maximum!pred(range, e);
}

 
 

 
Rotator!Range rotator(Range)(Range r) {
    return Rotator!Range(r);
}

 
struct Rotator(Range)
if (isForwardRange!Range && hasLength!Range) {
    size_t cnt;
    Range start, now;
    this(Range r) {
        cnt = 0;
        start = r.save;
        now = r.save;
    }
    this(this) {
        start = start.save;
        now = now.save;
    }
    @property bool empty() {
        return now.empty;
    }
    @property auto front() {
        assert(!now.empty);
        import std.range : take, chain;
        return chain(now, start.take(cnt));
    }
    @property Rotator!Range save() {
        return this;
    }
    void popFront() {
        cnt++;
        now.popFront;
    }
}

 
 
/* IMPORT /Users/yosupo/Program/dcomp/source/dcomp/ascii.d */
// module dcomp.ascii;

 
struct ASCIIString {
    string s;
    alias s this;
    this(string s) {
        this.s = s;
    }
    ref immutable(char) front() const {
        return s[0];
    }
    void popFront() {
        s = s[1..$];
    }
    ref immutable(char) back() const {
        return s[$-1];
    }
    void popBack() {
        s = s[0..$-1];
    }
}

 
 
/* IMPORT /Users/yosupo/Program/dcomp/source/dcomp/foundation.d */
// module dcomp.foundation;
 
static if (__VERSION__ <= 2070) {
    template fold(fun...) if (fun.length >= 1) {
        auto fold(R, S...)(R r, S seed) {
            import std.algorithm : reduce;
            static if (S.length < 2) {
                return reduce!fun(seed, r);
            } else {
                import std.typecons : tuple;
                return reduce!fun(tuple(seed), r);
            }
        }
    }
     
}
version (X86) static if (__VERSION__ < 2071) {
    int bsf(ulong v) {
        foreach (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;
    }
    int bsr(ulong v) {
        foreach_reverse (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;   
    }
    int popcnt(ulong v) {
        int c = 0;
        foreach (i; 0..64) {
            if (v & (1UL << i)) c++;
        }
        return c;
    }
}