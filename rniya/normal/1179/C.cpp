#include <bits/stdc++.h>
using namespace std;

template<typename Monoid,typename OperatorMonoid>
struct LazySegmentTree{
    typedef function<Monoid(Monoid,Monoid)> F;
    typedef function<Monoid(Monoid,OperatorMonoid)> G;
    typedef function<OperatorMonoid(OperatorMonoid,OperatorMonoid)> H;
    int n,hi;
    F f;
    G g;
    H h;
    Monoid id0;
    OperatorMonoid id1;
    vector<Monoid> dat;
    vector<OperatorMonoid> laz;
    LazySegmentTree(int n_,F f,G g,H h,Monoid id0,OperatorMonoid id1):
                    f(f),g(g),h(h),id0(id0),id1(id1){init(n_);}
    void init(int n_){
        n=1,hi=0;
        while(n<n_) n<<=1,++hi;
        dat.assign(n<<1,id0);
        laz.assign(n<<1,id1);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    inline Monoid reflect(int k){
        return laz[k]==id1?dat[k]:g(dat[k],laz[k]);
    }
    inline void propagate(int k){
        if (laz[k]==id1) return;
        laz[k<<1|0]=h(laz[k<<1|0],laz[k]);
        laz[k<<1|1]=h(laz[k<<1|1],laz[k]);
        dat[k]=reflect(k);
        laz[k]=id1;
    }
    inline void thrust(int k){
        for (int i=hi;i;--i) propagate(k>>i);
    }
    inline void recalc(int k){
        while(k>>=1) dat[k]=f(reflect(k<<1|0),reflect(k<<1|1));
    }
    void update(int a,int b,OperatorMonoid x){
        if (a>=b) return;
        thrust(a+=n); thrust(b+=n-1);
        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if (l&1) laz[l]=h(laz[l],x),++l;
            if (r&1) --r,laz[r]=h(laz[r],x);
        }
        recalc(a); recalc(b);
    }
    void set_val(int k,Monoid x){
        thrust(k+=n);
        dat[k]=x,laz[k]=id1;
        recalc(k);
    }
    Monoid query(int a,int b){
        if (a>=b) return id0;
        thrust(a+=n); thrust(b+=n-1);
        Monoid vl=id0,vr=id0;
        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,reflect(l++));
            if (r&1) vr=f(reflect(--r),vr);
        }
        return f(vl,vr);
    }
    template<typename C>
    int find_subtree(int k,const C &check,Monoid &M,bool type){
        while(k<n){
            propagate(k);
            Monoid nxt=type?f(reflect(k<<1|type),M):f(M,reflect(k<<1|type));
            if (check(nxt)) k=k<<1|type;
            else M=nxt,k=k<<1|(type^1);
        }
        return k-n;
    }
    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy "check"
    template<typename C>
    int find_first(int a,const C &check){
        Monoid L=id0;
        if (a<=0){
            if (check(f(L,reflect(1)))) return find_subtree(1,check,L,false);
            return -1;
        }
        thrust(a+n);
        int b=n;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1){
                Monoid nxt=f(L,reflect(l));
                if (check(nxt)) return ffind_subtree(l,check,L,false);
                L=nxt; ++l;
            }
        }
        return -1;
    }
    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy "check"
    template<typename C>
    int find_last(int b,const C &check){
        Monoid R=id0;
        if (b>=n){
            if (check(f(reflect(1),R))) return find_subtree(1,check,R,true);
            return -1;
        }
        thrust(b+n-1);
        int a=n;
        for (int l=a,r=b+n;l<r;l>>=1,r>>=1){
            if (r&1){
                Monoid nxt=f(reflect(--r),R);
                if (check(nxt)) return find_subtree(r,check,R,true);
                R=nxt;
            }
        }
        return -1;
    }
    Monoid operator[](int i){return query(i,i+1);}
};

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D
// RUQ

void DSL_2_D(){
    int n,q; cin >> n >> q;
    auto f=[](int a,int b){return min(a,b);};
    auto g=[](int a,int b){return (~b?b:a);};
    auto h=[](int a,int b){return b;};
    LazySegmentTree<int,int> seg(n,f,g,h,INT_MAX,-1);
    for (;q--;){
        int c,s,t,x,i; cin >> c;
        if (!c){
            cin >> s >> t >> x;
            seg.update(s,t+1,x);
        } else {
            cin >> i;
            cout << seg[i] << '\n';
        }
    }
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
// RAQ

void DSL_2_E(){
    int n,q; cin >> n >> q;
    auto f=[](int a,int b){return a+b;};
    LazySegmentTree<int,int> seg(n,f,f,f,0,0);
    for (;q--;){
        int c,s,t,x,i; cin >> c;
        if (!c){
            cin >> s >> t >> x;
            seg.update(s-1,t,x);
        } else {
            cin >> i;
            cout << seg[i-1] << '\n';
        }
    }
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
// RMQ and RAQ

void DSL_2_F(){
    int n,q; cin >> n >> q;
    auto f=[](int a,int b){return min(a,b);};
    auto g=[](int a,int b){return (~b?b:a);};
    auto h=[](int a,int b){return b;};
    LazySegmentTree<int,int> seg(n,f,g,h,INT_MAX,-1);
    for (;q--;){
        int c,s,t,x; cin >> c >> s >> t;
        if (!c){
            cin >> x;
            seg.update(s,t+1,x);
        } else cout << seg.query(s,t+1) << '\n';
    }
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
// RSQ and RUQ

void DSL_2_G(){
    int n,q; cin >> n >> q;
    auto f=[](pair<long long,long long> a,pair<long long,long long> b){return make_pair(a.first+b.first,a.second+b.second);};
    auto g=[](pair<long long,long long> a,long long x){return make_pair(a.first+a.second*x,a.second);};
    auto h=[](long long a,long long b){return a+b;};
    LazySegmentTree<pair<long long,long long>,long long> seg(n,f,g,h,{0,0},0);
    vector<pair<long long,long long>> v(n,{0,1});
    seg.build(v);
    for (;q--;){
        int c,s,t,x; cin >> c >> s >> t;
        if (!c){
            cin >> x;
            seg.update(s-1,t,x);
        } else cout << seg.query(s-1,t).first << '\n';
    }
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
// RMQ and RAQ

void DSL_2_H(){
    int n,q; cin >> n >> q;
    auto f=[](int a,int b){return min(a,b);};
    auto g=[](int a,int b){return a+b;};
    LazySegmentTree<int,int> seg(n,f,g,g,INT_MAX,0);
    vector<int> v(n,0);
    seg.build(v);
    for (;q--;){
        int c,s,t,x; cin >> c >> s >> t;
        if (!c){
            cin >> x;
            seg.update(s,t+1,x);
        } else cout << seg.query(s,t+1) << '\n';
    }
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
// RSQ and RUQ

void DSL_2_I(){
    const int inf=1<<30;
    int n,q; cin >> n >> q;
    auto f=[](pair<long long,long long> a,pair<long long,long long> b){return make_pair(a.first+b.first,a.second+b.second);};
    auto g=[](pair<long long,long long> a,long long x){return make_pair(x!=inf?x*a.second:a.first,a.second);};
    auto h=[](long long a,long long b){return b;};
    LazySegmentTree<pair<long long,long long>,long long> seg(n,f,g,h,{0,0},inf);
    vector<pair<long long,long long>> v(n,{0,1});
    seg.build(v);
    for (;q--;){
        int c,s,t,x; cin >> c >> s >> t;
        if (!c){
            cin >> x;
            seg.update(s,t+1,x);
        } else cout << seg.query(s,t+1).first << '\n';
    }
}

// https://atcoder.jp/contests/abc177/tasks/abc177_f

void ABC177_F(){
    const int INF=1e9;
    int H,W; cin >> H >> W;
    vector<int> A(H),B(H);
    for (int i=0;i<H;++i) cin >> A[i] >> B[i],--A[i];

    auto f=[](int a,int b){return min(a,b);};
    auto g=[](int a,int x){return x!=-1?x:a;};
    auto h=[](int a,int b){return b;};
    LazySegmentTree<int,int> seg(W,f,g,h,INF,-1)
                            ,nseg(W,f,g,h,W,-1);
    vector<int> v(W,0);
    seg.build(v);
    iota(v.begin(),v.end(),0);
    nseg.build(v);

    for (int i=0;i<H;++i){
        int l=nseg.find_last(W,[&](int x){return x<A[i];})+1;
        int r=nseg.find_last(W,[&](int x){return x<B[i];});
        if (~r&&B[i]<W) seg.set_val(B[i],min(seg[B[i]],B[i]-r));
        nseg.update(l,r+1,B[i]);
        seg.update(A[i],B[i],INF);
        int ans=seg.query(0,W);
        cout << (ans==INF?-1:ans+i+1) << '\n';
    }
}

// https://codeforces.com/contest/1179/problem/C

void CFR569_C(){
    const int MAX_A=1e6+10,INF=1e9;
    int n,m; cin >> n >> m;
    vector<int> a(n),b(m);
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<m;++i) cin >> b[i];

    auto f=[](int a,int b){return min(a,b);};
    auto g=[](int a,int b){return a+b;};
    LazySegmentTree<int,int> seg(MAX_A,f,g,g,INF,0);
    vector<int> v(MAX_A,0);
    seg.build(v);
    for (int i=0;i<n;++i) seg.update(a[i],MAX_A,1);
    for (int i=0;i<m;++i) seg.update(b[i],MAX_A,-1);

    int q; cin >> q;
    for (;q--;){
        int t,i,x; cin >> t >> i >> x; --i;
        if (t==1){
            seg.update(a[i],MAX_A,-1);
            a[i]=x;
            seg.update(a[i],MAX_A,1);
        } else {
            seg.update(b[i],MAX_A,1);
            b[i]=x;
            seg.update(b[i],MAX_A,-1);
        }
        int ans=seg.find_last(MAX_A,[&](int x){return x<n-m;});
        cout << (ans<0?-1:ans+1) << '\n';
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    CFR569_C();
}