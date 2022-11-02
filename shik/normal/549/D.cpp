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

#define N 110

struct BIT {
    int dat[N][N];
    void ins( int x, int y, int v ) {
        for ( int i=x; i; i-=i&-i )
            for ( int j=y; j; j-=j&-j )
                dat[i][j]+=v;
    }
    int ask( int x, int y ) {
        int s=0;
        for ( int i=x; i<N; i+=i&-i )
            for ( int j=y; j<N; j+=j&-j )
                s+=dat[i][j];
        return s;
    }
} bit;

int n,m;
char s[N][N];

int main() {
    RI(n,m);
    REP1(i,1,n) scanf("%s",s[i]+1);
    int ans=0;
    for ( int i=n; i>=1; i-- ) for ( int j=m; j>=1; j-- ) {
        int v=bit.ask(i,j);
        int d=(s[i][j]=='W'?+1:-1)-v;
        if ( d==0 ) continue;
        bit.ins(i,j,d);
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}