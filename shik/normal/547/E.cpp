// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}

template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) _dump(#__VA_ARGS__, __VA_ARGS__);

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }

// }}}

#define MS0(a,n) memset((a),0,n*sizeof(*(a)))
const int MXN = 400010;
struct SA{
    bool _t[MXN*2];
    int _s[MXN*2], _sa[MXN*2], _c[MXN*2], x[MXN], _p[MXN], _q[MXN*2], hei[MXN], r[MXN];
    int operator [] (int i){ return _sa[i]; }
    void build(int *s, int n, int m){
        memcpy(_s, s, sizeof(int) * n);
        sais(_s, _sa, _p, _q, _t, _c, n, m);
        mkhei(n);
    }
    void mkhei(int n){
        REP(i,n) r[_sa[i]] = i;
        hei[0] = 0;
        REP(i,n) if(r[i]) {
            int ans = i>0 ? max(hei[r[i-1]] - 1, 0) : 0;
            while(_s[i+ans] == _s[_sa[r[i]-1]+ans]) ans++;
            hei[r[i]] = ans;
        }
    }
    void sais(int *s, int *sa, int *p, int *q, bool *t, int *c, int n, int z){
        bool uniq = t[n-1] = true, neq;
        int nn = 0, nmxz = -1, *nsa = sa + n, *ns = s + n, lst = -1;
#define MAGIC(XD) MS0(sa, n); \
        memcpy(x, c, sizeof(int) * z); \
        XD; \
        memcpy(x + 1, c, sizeof(int) * (z - 1)); \
        REP(i,n) if(sa[i] && !t[sa[i]-1]) sa[x[s[sa[i]-1]]++] = sa[i]-1; \
        memcpy(x, c, sizeof(int) * z); \
        for(int i = n - 1; i >= 0; i--) if(sa[i] && t[sa[i]-1]) sa[--x[s[sa[i]-1]]] = sa[i]-1;
        MS0(c, z);
        REP(i,n) uniq &= ++c[s[i]] < 2;
        REP(i,z-1) c[i+1] += c[i];
        if (uniq) { REP(i,n) sa[--c[s[i]]] = i; return; }
        for(int i = n - 2; i >= 0; i--) t[i] = (s[i]==s[i+1] ? t[i+1] : s[i]<s[i+1]);
        MAGIC(REP1(i,1,n-1) if(t[i] && !t[i-1]) sa[--x[s[i]]]=p[q[i]=nn++]=i);
        REP(i, n) if (sa[i] && t[sa[i]] && !t[sa[i]-1]) {
            neq=lst<0||memcmp(s+sa[i],s+lst,(p[q[sa[i]]+1]-sa[i])*sizeof(int));
            ns[q[lst=sa[i]]]=nmxz+=neq;
        }
        sais(ns, nsa, p + nn, q + n, t + n, c + z, nn, nmxz + 1);
        MAGIC(for(int i = nn - 1; i >= 0; i--) sa[--x[s[p[nsa[i]]]]] = p[nsa[i]]);
    }
} sa;

struct RMQ {
    int n,sml[19][MXN];
    void init( int *val, int _n ) {
        n=_n;
        REP(i,n) sml[0][i]=val[i];
        for ( int i=1; (1<<i)<=n; i++ ) {
            int l=(1<<i);
            for ( int j=0; j+l<=n; j++ ) sml[i][j]=min(sml[i-1][j],sml[i-1][j+l/2]);
        }
    }
    int ask( int l, int r ) {
        if ( l>r ) swap(l,r);
        if ( l==r ) return sml[0][l];
        int i=__lg(r-l+1);
        return min(sml[i][l],sml[i][r-(1<<i)+1]);
    }
} rmq;

inline int get_lcp( int i, int j ) {
    if ( i>j ) swap(i,j);
    return rmq.ask(i+1,j);
}

struct Seg {
    static Seg mem[20 * MXN], *pmem;
    int sz;
    Seg *lc, *rc;
    Seg() {}
    Seg(int l, int r) : sz(0) {
        if (l == r) return;
        int m = (l + r) / 2;
        lc = new (pmem++) Seg(l, m);
        rc = new (pmem++) Seg(m + 1, r);
    }
    Seg* ins(int l, int r, int x) {
        Seg *t = new (pmem++) Seg(*this);
        t->sz++;
        if (l != r) {
            int m = (l + r) / 2;
            if (x <= m) t->lc = t->lc->ins(l, m, x);
            else t->rc = t->rc->ins(m + 1, r, x);
        }
        return t;
    }
} Seg::mem[20 * MXN], *Seg::pmem = mem;

int ask(Seg *tl, Seg *tr, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tr->sz - tl->sz;
    int m = (l + r) / 2, ans = 0;
    if (ql <= m) ans += ask(tl->lc, tr->lc, l, m, ql, qr);
    if (qr > m) ans += ask(tl->rc, tr->rc, m + 1, r, ql, qr);
    return ans;
}

#define N 400010
int n,q,st[N],len[N],spos,pl[N],pr[N];
char s[N];
int is[N];
Seg *seg[N];
int main() {
    RI(n,q);
    REP1(i,1,n) {
        st[i]=spos;
        scanf("%s",s+st[i]);
        len[i]=strlen(s+st[i]);
        spos+=len[i]+1;
    }
    REP(i,spos) {
        if ( islower(s[i]) ) is[i]=s[i]-'a'+2;
        else is[i]=1;
    }
    is[spos-1]=0;
    sa.build(is,spos,30);
    //dump(VI(is,is+spos));
    //dump(VI(sa._sa,sa._sa+spos));
    //dump(VI(sa.r,sa.r+spos));
    rmq.init(sa.hei,spos);
    REP1(i,1,n) {
        int ri=sa.r[st[i]];
        int l=0,r=ri;
        while ( l!=r ) {
            int m=(l+r)/2;
            if ( m==ri || get_lcp(m,ri)>=len[i] ) r=m;
            else l=m+1;
        }
        pl[i]=l;
        l=ri;
        r=spos-1;
        while ( l!=r ) {
            int m=(l+r+1)/2;
            if ( m==ri || get_lcp(ri,m)>=len[i] ) l=m;
            else r=m-1;
        }
        pr[i]=l;
        //dump(i,ri,pl[i],pr[i]);
    }
    seg[0] = new (Seg::pmem++) Seg(0, spos - 1);
    REP1(i,1,n) {
        seg[i]=seg[i-1];
        REP(j,len[i]) {
            int x=sa.r[st[i]+j];
            seg[i]=seg[i]->ins(0,spos-1,x);
        }
    }
    while ( q-- ) {
        int l,r,k;
        RI(l,r,k);
        int ans=ask(seg[l-1],seg[r],0,spos-1,pl[k],pr[k]);
        printf("%d\n",ans);
    }
    return 0;
}