// shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_tuple
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

inline void gn( int &x ) {
    int ch;
    while ( (ch=getchar())<'0' || ch>'9' );
    x=ch-'0';
    while ( (ch=getchar())>='0' && ch<='9' ) x=x*10+ch-'0';
}

const int N=300010;
const int M=4*N;
const int H=131;
const LL MOD=1000000297;
LL pw[N];
struct Seg {
    LL h[M];
    void init( int n, char s[] ) {
        REP1(i,1,n) h[i]=(h[i-1]*H+s[i])%MOD;
    }
    LL ask( int l, int r ) {
        LL s=(h[r]-h[l-1]*pw[r-l+1])%MOD;
        if ( s<0 ) s+=MOD;
        return s;
    }
} seg1,seg2;

int n;
char str[N];
VI e[N];
void input() {
    gn(n);
    scanf("%s",str+1);
    REP(i,n-1) {
        int a,b;
        gn(a); gn(b);
        e[a].PB(b);
        e[b].PB(a);
    }
}

int sz[N];
int get_sz( int p, int f ) {
    sz[p]=1;
    FOR(it,e[p]) if ( *it!=f ) sz[p]+=get_sz(*it,p);
    return sz[p];
}

int st[N],ed[N],pid,fa[N],dep[N],root[N];
void dfs( int p, int f, int lv ) {
    st[p]=++pid;
    fa[p]=f;
    dep[p]=lv;
    int w=0;
    FOR(it,e[p]) if ( *it!=f && (!w || sz[*it]>sz[w]) ) w=*it;
    if ( w ) {
        root[w]=root[p];
        dfs(w,p,lv+1);
        FOR(it,e[p]) if ( *it!=f && *it!=w ) {
            root[*it]=*it;
            dfs(*it,p,lv+1);
        }
    }
    ed[p]=pid;
}

char str1[N],str2[N];
int st1[N],st2[N];
void build() {
    get_sz(1,0);
    root[1]=1;
    pid=0;
    dfs(1,0,1);
    REP1(i,1,n) st1[i]=st[i];
    REP1(i,1,n) st2[i]=n-st1[i]+1;
    REP1(i,1,n) str1[st1[i]]=str[i];
    REP1(i,1,n) str2[st2[i]]=str[i];
    seg1.init(n,str1);
    seg2.init(n,str2);
}

vector<tuple<int,int,int>> get_path( int a, int b ) {
   vector<tuple<int,int,int>> v1,v2;
   while ( root[a]!=root[b] ) {
       if ( dep[root[a]]<dep[root[b]] ) {
           v2.PB(MP(1,st1[root[b]],st1[b]));
           b=fa[root[b]];
       } else {
           v1.PB(MP(2,st2[a],st2[root[a]]));
           a=fa[root[a]];
       }
   }
   if ( dep[a]<dep[b] ) v2.PB(MP(1,st1[a],st1[b]));
   else v1.PB(MP(2,st2[a],st2[b]));
   v1.insert(v1.end(),v2.rbegin(),v2.rend());
   //FOR(it,v1) printf("(%d,%d,%d) ",get<0>(*it),get<1>(*it),get<2>(*it)); puts("");
   return v1;
}

LL ask( int s, int l, int r ) {
    //assert(l<=r);
    if ( s==1 ) return seg1.ask(l,r);
    else return seg2.ask(l,r);
}

void solve() {
    int q,a,b,c,d;
    gn(q);
    while ( q-- ) {
        gn(a); gn(b); gn(c); gn(d);
        //printf("%d,%d,%d,%d\n",a,b,c,d);
        auto v1=get_path(a,b);
        auto v2=get_path(c,d);
        int lcp=0,i1=0,i2=0;
        while ( i1<SZ(v1) && i2<SZ(v2) ) {
            auto &p1=v1[i1],&p2=v2[i2];
            int s1,l1,r1,s2,l2,r2;
            tie(s1,l1,r1)=p1;
            tie(s2,l2,r2)=p2;
            //printf("%d,%d,%d %d,%d,%d\n",s1,l1,r1,s2,l2,r2);
            int n1=r1-l1+1;
            int n2=r2-l2+1;
            if ( n1<n2 ) {
                LL h1=ask(s1,l1,r1);
                LL h2=ask(s2,l2,l2+n1-1);
                if ( h1==h2 ) {
                    lcp+=n1;
                    i1++;
                    get<1>(p2)+=n1;
                } else break;
            } else if ( n1>n2 ) {
                LL h1=ask(s1,l1,l1+n2-1);
                LL h2=ask(s2,l2,r2);
                if ( h1==h2 ) {
                    lcp+=n2;
                    i2++;
                    get<1>(p1)+=n2;
                } else break;
            } else {
                LL h1=ask(s1,l1,r1);
                LL h2=ask(s2,l2,r2);
                if ( h1==h2 ) {
                    lcp+=n1;
                    i1++;
                    i2++;
                } else break;
            }
        }
        //printf("%d,%d,%d,%d\n",a,b,c,d);
        if ( i1<SZ(v1) && i2<SZ(v2) ) {
            auto &p1=v1[i1],&p2=v2[i2];
            int s1,l1,r1,s2,l2,r2;
            tie(s1,l1,r1)=p1;
            tie(s2,l2,r2)=p2;
            int n1=r1-l1+1;
            int n2=r2-l2+1;
            int bl=0,br=min(n1,n2);
            while ( bl!=br ) {
                int bm=(bl+br+1)/2;
                LL h1=ask(s1,l1,l1+bm-1);
                LL h2=ask(s2,l2,l2+bm-1);
                if ( h1==h2 ) bl=bm;
                else br=bm-1;
            }
            lcp+=bl;
        }
        printf("%d\n",lcp);
    }
}

int main() {
    pw[0]=1;
    REP1(i,1,N-1) pw[i]=pw[i-1]*H%MOD;
    input();
    build();
    solve();
    return 0;
}