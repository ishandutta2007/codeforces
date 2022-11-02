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
    int x,y;
};

int sq( int x ) { return x*x; }
int dis2( const P &a, const P &b ) { return sq(a.x-b.x)+sq(a.y-b.y); }
int eval( int n, P p[] ) {
    int s=0;
    REP(i,n) REP(j,i) s+=dis2(p[i],p[j]);
    return s;
}
int eval_one( int n, int k, P p[] ) {
    int s=0;
    REP(i,n) s+=dis2(p[i],p[k]);
    return s;
}

#define N 8
#define R 64
vector<P> gp;
int n,r;
P sol[N],p[N];

void shik() {
    REP(i,n) p[i]=gp[rand()%gp.size()]; // TODO
    int per[N];
    REP(i,n) per[i]=i;
    int now=eval(n,p);
    while ( 1 ) {
        random_shuffle(per,per+n);
        REP(ii,n) {
            int i=per[ii];
            int mx=-1;
            P mxp{-1,-1};
            FOR(it,gp) {
                p[i]=*it;
                int val=eval_one(n,i,p);
                if ( val>mx ) {
                    mx=val;
                    mxp=*it;
                }
            }
            p[i]=mxp;
        }
        int val=eval(n,p);
        if ( val<=now ) break;
        now=val;
    }
}

int main() {
    srand(time(0)+getpid());
    RI(n,r);
    REP1(i,-r,+r) REP1(j,-r,+r) if ( i*i+j*j<=r*r ) gp.PB(P{i,j});
    REP(i,n) sol[i]=P{0,0};
    while ( clock()<2.9*CLOCKS_PER_SEC ) {
        shik();
        if ( eval(n,p)>eval(n,sol) ) {
            REP(i,n) sol[i]=p[i];
        }
    }
    int ans=eval(n,sol);
    printf("%d\n",ans);
    REP(i,n) printf("%d %d\n",sol[i].x,sol[i].y);
    return 0;
}