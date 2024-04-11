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

typedef long double LD;
LD read_ld() {
    double x;
    scanf("%lf",&x);
    return x;
}
LD a,b,c,d;
bool chk( LD m ) {
    LD la=a-m,ra=a+m;
    LD lb=b-m,rb=b+m;
    LD lc=c-m,rc=c+m;
    LD ld=d-m,rd=d+m;
    LD v1[4]={la*ld,la*rd,ra*ld,ra*rd};
    LD v2[4]={lb*lc,lb*rc,rb*lc,rb*rc};
    LD l1=*min_element(v1,v1+4);
    LD r1=*max_element(v1,v1+4);
    LD l2=*min_element(v2,v2+4);
    LD r2=*max_element(v2,v2+4);
    LD l3=max(l1,l2);
    LD r3=min(r1,r2);
    return l3<=r3;
}
int main() {
    a=read_ld();
    b=read_ld();
    c=read_ld();
    d=read_ld();
    LD l=0,r=2e9;
    REP(i,1000) {
        LD m=(l+r)/2;
        if ( chk(m) ) r=m;
        else l=m;
    }
    double ans=(l+r)/2;
    printf("%.12f\n",ans);
    return 0;
}