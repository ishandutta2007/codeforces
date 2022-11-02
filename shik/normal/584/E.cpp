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

#ifdef SHIK
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

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0);

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
#else
#define dump(...)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

const int N=2014;
int n,p[N],q[N],iq[N],r[N];

LL ans;
vector<PII> sol;
void meow( int a, int b ) {
    ans+=abs(a-b);
    sol.PB({a,b});
    swap(p[a],p[b]);
    swap(r[a],r[b]);
    dump(a,b,VI(p+1,p+n+1));
}

int main() {
    RI(n);
    REP1(i,1,n) RI(p[i]);
    REP1(i,1,n) RI(q[i]);
    REP1(i,1,n) iq[q[i]]=i;
    REP1(i,1,n) r[i]=iq[p[i]];
    dump(VI(r+1,r+n+1));
    REP1(i,1,n) {
        int p=find(r+1,r+n+1,i)-r;
        for ( int j=p-1; j>=i; j-- ) if ( r[j]>=p ) {
            meow(j,p);
            p=j;
        }
        assert(p==i);
    }
    REP1(i,1,n) assert(p[i]==q[i]);
    cout<<ans<<endl;
    printf("%d\n",SZ(sol));
    for ( auto i:sol ) printf("%d %d\n",i.first,i.second);
    return 0;
}