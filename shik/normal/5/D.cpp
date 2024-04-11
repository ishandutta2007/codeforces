// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
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

double dis( double v0, double a, double t ) {
    return v0*t + 0.5 * a * t * t;
}

int main() {
    double a,v,l,d,w,ans=0;
    cin>>a>>v>>l>>d>>w;
    auto check = [&]( double x, double vx ) -> bool {
        if ( x>l ) return 0;
        if ( vx>v ) return 0;
        if ( vx<0 ) return 0;
        if ( x>d ) return 1;
        if ( vx<=w ) return 1;
        double t=(vx-w)/a;
        if ( x+dis(vx,-a,t)<=d ) return 1;
        return 0;
    };
    double x=0,vx=0;
    double lt=0,mt,rt=10000;
    REP(i,100) {
        mt=(lt+rt)/2;
        double mx=dis(0,a,mt);
        double mv=mt*a;
        if ( mx<=d && check(mx,mv) ) lt=mt;
        else rt=mt;
    }
    mt=lt;
    x+=dis(0,a,mt);
    vx+=mt*a;
    ans+=mt;
    //printf("mt = %f, x = %f, vx = %f\n",mt,x,vx);
    lt=0; rt=10000;
    REP(i,100) {
        mt=(lt+rt)/2;
        double mx=x+dis(vx,0,mt);
        if ( mx<=d && check(mx,vx) ) lt=mt;
        else rt=mt;
    }
    mt=(lt+rt)/2;
    x+=dis(vx,0,mt);
    ans+=mt;
    //printf("mt = %f, x = %f, vx = %f\n",mt,x,vx);
    lt=0; rt=10000;
    REP(i,100) {
        mt=(lt+rt)/2;
        double mx=x+dis(vx,-a,mt);
        double mv=vx+mt*-a;
        if ( mv>=0 && mx<=d ) lt=mt;
        else rt=mt;
    }
    mt=(lt+rt)/2;
    x+=dis(vx,-a,mt);
    vx+=mt*-a;
    //printf("mt = %f, x = %f, vx = %f\n",mt,x,vx);
    ans+=mt;
    lt=0; rt=10000;
    REP(i,100) {
        mt=(lt+rt)/2;
        double mx=x+dis(vx,a,mt);
        double mv=vx+mt*a;
        if ( check(mx,mv) ) lt=mt;
        else rt=mt;
    }
    mt=(lt+rt)/2;
    x+=dis(vx,a,mt);
    vx+=mt*a;
    //printf("mt = %f, x = %f, vx = %f\n",mt,x,vx);
    ans+=mt;
    lt=0; rt=10000;
    REP(i,100) {
        mt=(lt+rt)/2;
        double mx=x+dis(vx,0,mt);
        if ( mx<=l ) lt=mt;
        else rt=mt;
    }
    mt=(lt+rt)/2;
    x+=dis(vx,0,mt);
    //printf("mt = %f, x = %f, vx = %f\n",mt,x,vx);
    ans+=mt;
    printf("%.9f\n",ans);
    return 0;
}