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

#define y1 _shik_y1

double dis( double x, double y ) {
    return sqrt(x*x+y*y);
}

double x1,y1,x2,y2,vmx,wt,vx,vy,wx,wy,x3,y3;
int main() {
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    scanf("%lf%lf",&vmx,&wt);
    scanf("%lf%lf",&vx,&vy);
    scanf("%lf%lf",&wx,&wy);
    
    x3=x2-x1;
    y3=y2-y1;

    {
        double x4=x3-wt*vx;
        double y4=y3-wt*vy;
        if ( dis(x4,y4)<=wt*vmx ) {
            double l=0,r=wt;
            REP(i,100) {
                double m=(l+r)/2;
                x4=x3-m*vx;
                y4=y3-m*vy;
                if ( dis(x4,y4)<=m*vmx ) r=m;
                else l=m;
            }
            double ans=(l+r)/2;
            printf("%.12f\n",ans);
            return 0;
        }
    }

    {
        x3-=wt*vx;
        y3-=wt*vy;
        auto chk=[&]( double t ) {
            double x4=x3-t*wx;
            double y4=y3-t*wy;
            return dis(x4,y4)<=(wt+t)*vmx;
        };
        double l=0,r=1;
        while ( !chk(r) ) r*=2;
        REP(i,100) {
            double m=(l+r)/2;
            if ( chk(m) ) r=m;
            else l=m;
        }
        double ans=wt+(l+r)/2;
        printf("%.12f\n",ans);
    }

    return 0;
}