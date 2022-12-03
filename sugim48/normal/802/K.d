/+ dub.sdl:
    name "K"
    dependency "dcomp" version=">=0.6.0"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dcomp.foundation, dcomp.scanner;
import std.typecons;

int main() {
    auto sc = new Scanner(stdin);
    alias Edge = Tuple!(int, "to", int, "dist");
    int n, k;
    sc.read(n, k);
    Edge[][] g = new Edge[][](n+1);
    g[n] ~= Edge(0, 0); g[0] ~= Edge(n, 0);
    foreach (i; 0..n-1) {
        int a, b, c;
        sc.read(a, b, c);
        g[a] ~= Edge(b, c);
        g[b] ~= Edge(a, c);
    }

    int[2] dfs(int p, int b, int d) {
        if (p == n) return dfs(0, p, g[n][0].dist);
        int m = g[p].length.to!int - 1;
        int[2][] bu = new int[2][m];
        int co = 0;
        foreach (e; g[p]) {
            if (e.to == b) continue;
            bu[co] = dfs(e.to, p, e.dist);
            co++;
        }
        bu.sort!"a[0]>b[0]";
        int[2] res; res[0] += d;
        int ma = 0;
        foreach (i; 0..min(m, k-1)) {
            res[0] += bu[i][0];
            ma = max(ma, bu[i][1] - bu[i][0]);
        }
        res[1] = res[0] + ma;
        if (k <= m) {
            res[1] = max(res[1], res[0] + ma + bu[k-1][0]);
            int ma2 = 0;
            foreach (i; k-1..m) {
                ma2 = max(ma2, bu[i][1]);
            }
            res[1] = max(res[1], res[0] + ma2);
        }
        return res;
    }

    writeln(dfs(n, -1, 0)[1]);
    return 0;
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