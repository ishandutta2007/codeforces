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

const int N=2e5+10;
int n,a[N],l[N],r[N],sa[N],ans[N];

bool cmp( int x, int y ) {
    return a[x]>a[y];
}

bool vis[N];

int main() {
    RI(n);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,n) l[i]=r[i]=sa[i]=i;
    sort(sa+1,sa+n+1,cmp);
    REP1(ii,1,n) {
        int i=sa[ii];
        vis[i]=1;
        int ll=i,rr=i;
        if ( i>1 && vis[i-1] ) {
            l[i]=l[i-1];
            r[l[i-1]]=i;
            ll=l[i-1];
        }
        if ( i<n && vis[i+1] ) {
            r[l[i]]=r[i+1];
            l[r[i+1]]=l[i];
            rr=r[i+1];
        }
        int sz=rr-ll+1;
        ans[sz]=max(ans[sz],a[i]);
    }
    for ( int i=n-1; i>=0; i-- ) ans[i]=max(ans[i],ans[i+1]);
    REP1(i,1,n) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}