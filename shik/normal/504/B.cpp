// by shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}

template<typename T>
void _err( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _err( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _err(s+1,tail...);
}

#define err(...) _err(#__VA_ARGS__, __VA_ARGS__);

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

/// }}}

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;

#define N 200010

void conv( int n, int p[], int a[] ) {
    set_t s;
    REP(i,n) s.insert(i);
    REP(i,n) {
        a[i]=s.order_of_key(p[i]);
        s.erase(p[i]);
    }
}

void iconv( int n, int a[], int p[] ) {
    set_t s;
    REP(i,n) s.insert(i);
    REP(i,n) {
        p[i]=*s.find_by_order(a[i]);
        s.erase(p[i]);
    }
}
    
int n,p[N],q[N],r[N],a[N],b[N],c[N];
int main() {
    RI(n);
    REP(i,n) RI(p[i]);
    REP(i,n) RI(q[i]);
    conv(n,p,a);
    conv(n,q,b);
    REP(i,n) c[i]=a[i]+b[i];
    assert(c[n-1]==0);
    for ( int i=n-1; i>=0; i-- ) {
        if ( i>0 ) c[i-1]+=c[i]/(n-i);
        c[i]%=n-i;
    }
    iconv(n,c,r);
    REP(i,n) printf("%d%c",r[i]," \n"[i==n-1]);
    return 0;
}