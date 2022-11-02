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

const int N=5140;
int n;
char s[N];
LL dp[N/2][N/2];
LL eval( int l, int r ) {
    if ( l>r ) return 0;
    assert(l%2==0 && r%2==0);
    LL &ret=dp[l/2][r/2];
    if ( ret!=-1 ) return ret;
    if ( l==r ) return ret=s[l]-'0';
    LL now=s[l]-'0';
    while ( l+1<r && s[l+1]=='*' ) {
        l+=2;
        now*=s[l]-'0';
    }
    ret=now+eval(l+2,r);
    return ret;
}
LL eval_par( int l, int r ) {
    LL mv=eval(l,r);
    while ( l-1>0 && s[l-1]=='*' ) {
        l-=2;
        mv*=s[l]-'0';
    }
    while ( r+1<n && s[r+1]=='*' ) {
        r+=2;
        mv*=s[r]-'0';
    }
    LL lv=eval(0,l-2);
    LL rv=eval(r+2,n-1);
    return lv+mv+rv;
}
int main() {
    memset(dp,-1,sizeof(dp));
    n=strlen(gets(s));
    LL ans=eval(0,n-1);
    for ( int i=0; i<n; i+=2 ) for ( int j=0; j<n; j+=2 )
        if ( (i>0 && s[i-1]=='*') || (j+1<n && s[j+1]=='*') ) ans=max(ans,eval_par(i,j));
    cout<<ans<<endl;
    return 0;
}