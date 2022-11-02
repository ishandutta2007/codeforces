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
// }}}


struct P {
    int x,y,z;
    void read() {
        RI(x,y,z);
        x<<=3;
        y<<=3;
        z<<=3;
    }
    void print() {
        printf("%d %d %d\n",x>>3,y>>3,z>>3);
    }
    void debug() {
        printf("%d %d %d\n",x,y,z);
    }
} p[8];

inline bool operator ==( const P &a, const P &b ) { return tie(a.x,a.y,a.z)==tie(b.x,b.y,b.z); }
inline void operator +=( P &a, const P &b ) {
    a.x+=b.x;
    a.y+=b.y;
    a.z+=b.z;
}
inline void operator /=( P &a, const int &b ) {
    a.x/=b;
    a.y/=b;
    a.z/=b;
}
inline P mirror( const P &a, const P &b ) { return P{2*b.x-a.x,2*b.y-a.y,2*b.z-a.z}; }
inline P operator -( const P &a, const P &b ) { return P{a.x-b.x,a.y-b.y,a.z-b.z}; }
inline LL dot( const P &a, const P &b ) { return 1LL*a.x*b.x+1LL*a.y*b.y+1LL*a.z*b.z; }
inline LL dot3( const P &o, const P &a, const P &b ) { return dot(a-o,b-o); }
inline LL dis2( const P &a, const P &b ) { return dot(a-b,a-b); }

bool _check() {
    P o{0,0,0};
    REP(i,8) o+=p[i];
    o/=8;
    LL d=dis2(o,p[0]);
    REP1(i,1,7) if ( dis2(o,p[i])!=d ) return 0;
    LL md=1e18;
    REP(i,8) REP(j,i) if ( p[i]==p[j] ) return 0;
    REP(i,8) REP(j,i) md=min(md,dis2(p[i],p[j]));
    int w=-1;
    REP1(i,1,7) if ( dis2(p[0],p[i])==md ) {
        w=i;
        break;
    }
    swap(p[1],p[w]);
    REP(i,4) {
        P q=mirror(p[i],o);
        int w=-1;
        REP1(j,i+1,7-i) if ( p[j]==q ) {
            w=j;
            break;
        }
        if ( w==-1 ) return 0;
        swap(p[w],p[7-i]);
    }
    bool good1=1;
    P o1=P{0,0,0};
    REP(i,4) o1+=p[i];
    o1/=4;
    REP(i,2) {
        P q=mirror(p[i],o1);
        int w=-1;
        REP1(j,i+1,3-i) if ( p[j]==q ) {
            w=j;
            break;
        }
        if ( w==-1 ) {
            good1=0;
            break;
        }
        swap(p[w],p[3-i]);
        swap(p[7-w],p[7-(3-i)]);
    }
    if ( !good1 ) {
        swap(p[3],p[4]);
        o1=P{0,0,0};
        REP(i,4) o1+=p[i];
        o1/=4;
        REP(i,2) {
            P q=mirror(p[i],o1);
            int w=-1;
            REP1(j,i+1,3-i) if ( p[j]==q ) {
                w=j;
                break;
            }
            if ( w==-1 ) return 0;
            swap(p[w],p[3-i]);
            swap(p[7-w],p[7-(3-i)]);
        }
    }
#define XD(i,j,k) if ( dot3(p[i],p[j],p[k]) ) return 0
    XD(0,1,2);
    XD(0,1,4);
    XD(0,2,4);
    XD(1,0,3);
    XD(1,0,5);
    XD(1,3,5);
    XD(2,0,3);
    XD(2,0,6);
    XD(2,3,6);
    XD(3,1,2);
    XD(3,1,7);
    XD(3,2,7);
    XD(4,0,5);
    XD(4,0,6);
    XD(4,5,6);
    XD(5,1,4); // tmt514!!
    XD(5,1,7);
    XD(5,4,7);
    XD(6,2,4);
    XD(6,2,7);
    XD(6,4,7);
    XD(7,3,5);
    XD(7,3,6);
    XD(7,5,6);
    return 1;
}

bool check() {
    P pp[8];
    REP(i,8) pp[i]=p[i];
    bool ret=_check();
    REP(i,8) p[i]=pp[i];
    if ( ret ) {
        puts("YES");
        REP(i,8) p[i].print();
    }
    return ret;
}

bool go( int lv ) {
    if ( lv==8 ) return check();
    P q=p[lv];
    p[lv]=P{q.x,q.y,q.z};
    if ( go(lv+1) ) return 1;
    p[lv]=P{q.x,q.z,q.y};
    if ( go(lv+1) ) return 1;
    p[lv]=P{q.y,q.x,q.z};
    if ( go(lv+1) ) return 1;
    p[lv]=P{q.y,q.z,q.x};
    if ( go(lv+1) ) return 1;
    p[lv]=P{q.z,q.x,q.y};
    if ( go(lv+1) ) return 1;
    p[lv]=P{q.z,q.y,q.x};
    if ( go(lv+1) ) return 1;
    p[lv]=q;
    return 0;
}

int main() {
    REP(i,8) p[i].read();
    if ( !go(0) ) puts("NO");
    return 0;
}