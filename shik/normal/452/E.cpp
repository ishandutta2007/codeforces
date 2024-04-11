// shik {{{
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
// }}}

struct SA{
    static const int MXN = 300010;
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
#define MS0(x,n) memset((x),0,n*sizeof(*(x)))
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
};

#define N 300010
const int MOD=1e9+7;

inline void add( int &a, int b ) {
    a+=b;
    if ( a>=MOD ) a-=MOD;
}

inline void sub( int &a, int b ) {
    a-=b;
    if ( a<0 ) a+=MOD;
}

int f( int n ) {
    if ( n<3 ) return 0;
    else return 1LL*n*(n-1)*(n-2)/6%MOD;
}

int n1,n2,n3,m;
char s1[N],s2[N],s3[N];

int ans[N];
void solve( int sg, bool b1, bool b2, bool b3 ) {
    static int s[N],lt[N],rt[N];
    static vector<int> v[N];
    int n=0,m=1;
    if ( b1 ) {
        if ( n!=0 ) s[n++]=m++;
        REP(i,n1) s[n++]=s1[i];
    }
    if ( b2 ) {
        if ( n!=0 ) s[n++]=m++;
        REP(i,n2) s[n++]=s2[i];
    }
    if ( b3 ) {
        if ( n!=0 ) s[n++]=m++;
        REP(i,n3) s[n++]=s3[i];
    }
    s[n++]=0;
    SA *sa = new SA(); 
    sa->build(s,n,128);
    //REP(i,n) printf("%d ",(*sa)[i]); puts("");
    //REP(i,n) printf("%d ",sa->hei[i]); puts("");
    REP1(i,0,n) v[i].clear();
    REP(i,n) v[sa->hei[i]].PB(i);
    REP(i,n+1) lt[i]=rt[i]=i;
    auto g=[&]( int i ) { return f(i-lt[i]+1); };
    int now=0;
    for ( int i=n; i>=1; i-- ) {
        for ( int j : v[i] ) {
            sub(now,g(j));
            sub(now,g(rt[j+1]));
            rt[lt[j]]=rt[j+1];
            lt[rt[j+1]]=lt[j];
            add(now,g(rt[j+1]));
        }
        //printf("%d: %d\n",i,now);
        //for ( int j=0; j<=n; j=rt[j]+1 ) printf("(%d,%d) ",j,rt[j]); puts("");
        if ( sg==+1 ) add(ans[i],now);
        else sub(ans[i],now);
    }
    delete sa;
}

int main() {
    n1=strlen(gets(s1));
    n2=strlen(gets(s2));
    n3=strlen(gets(s3));
    m=min(n1,min(n2,n3));
    solve(+1,1,1,1);
    solve(-1,1,1,0);
    solve(-1,1,0,1);
    solve(-1,0,1,1);
    solve(+1,1,0,0);
    solve(+1,0,1,0);
    solve(+1,0,0,1);
    REP1(i,1,m) printf("%d%c",ans[i],i==m?'\n':' ');
    return 0;
}