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

#define N 300010
#define M 1000010

vector<int> app[M];
int ask( int l, int r, int v ) {
    auto it=lower_bound(ALL(app[v]),l);
    auto jt=upper_bound(ALL(app[v]),r);
    return jt-it;
}

int n,m,a[N],sa[N],ord[N],l[N],r[N];
bool vis[N];
bool cmp( int x, int y ) {
    return a[x]<a[y];
}
LL calc( int l1, int r1, int l2, int r2, int mx ) {
    LL ans=0;
    mx%=m;
    if ( r1-l1<=r2-l2 ) {
        REP1(i,l1-1,r1-1) {
            int x=sa[i]+mx;
            if ( x>=m ) x-=m;
            int now=ask(l2,r2,x);
            ans+=now;
        }
    } else {
        REP1(i,l2,r2) {
            int x=sa[i]-mx;
            if ( x<0 ) x+=m;
            int now=ask(l1-1,r1-1,x);
            ans+=now;
        }
    }
    return ans;
}
int main() {
    RI(n,m);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,n) l[i]=r[i]=i;
    REP1(i,1,n) ord[i]=i;
    REP1(i,1,n) sa[i]=(sa[i-1]+a[i])%m;
    REP1(i,0,n) app[sa[i]].PB(i);
    sort(ord+1,ord+n+1,cmp);
    LL ans=0;
    REP1(ii,1,n) {
        int i=ord[ii];
        vis[i]=1;
        if ( i>1 && vis[i-1] ) {
            ans+=calc(l[i-1],i-1,i,i,a[i]);
            l[i]=l[i-1];
            r[l[i-1]]=i;
        }
        if ( i<n && vis[i+1] ) {
            ans+=calc(l[i],i,i+1,r[i+1],a[i]);
            r[l[i]]=r[i+1];
            l[r[i+1]]=l[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}