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

int main() {
    LL m,h1,a1,x1,y1,h2,a2,x2,y2;
    cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
    LL hh1=h1,hh2=h2;
    REP1(i,1,2000000) {
        hh1=(x1*hh1+y1)%m;
        hh2=(x2*hh2+y2)%m;
        if ( hh1==a1 && hh2==a2 ) return printf("%d\n",i),0;
    }
    int t1=0;
    while ( h1!=a1 && t1<m ) {
        h1=(x1*h1+y1)%m;
        t1++;
    }
    int t2=0;
    while ( h2!=a2 && t2<m ) {
        h2=(x2*h2+y2)%m;
        t2++;
    }
    if ( h1!=a1 || h2!=a2 ) return puts("-1"),0;
    int l1=0;
    do {
        h1=(x1*h1+y1)%m;
        l1++;
    } while ( h1!=a1 && l1<m );
    int l2=0;
    do {
        h2=(x2*h2+y2)%m;
        l2++;
    } while ( h2!=a2 && l2<m );
    if ( h1!=a1 || h2!=a2 ) return puts("-1"),0;
    REP(i,2000000) {
        LL t=1LL*i*l1+t1;
        if ( t>=t2 && (t-t2)%l2==0 ) {
            cout<<t<<endl;
            return 0;
        }
    }
    puts("-1");
    return 0;
}