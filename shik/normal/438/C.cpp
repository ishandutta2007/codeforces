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

#define N 217
const int MOD=1e9+7;

inline int sgn( LL x ) { return (x>0)-(x<0); }

struct P {
    LL x,y;
    void read() {
        cin>>x>>y;
        x*=2;
        y*=2;
    }
    double ang() {
        return atan2(y,x);
    }
} p[N];

P operator -( const P &a, const P &b ) { return P{a.x-b.x,a.y-b.y}; }
LL operator *( const P &a, const P &b ) { return a.x*b.y-b.x*a.y; }
LL X( const P &o, const P &a, const P &b ) { return (a-o)*(b-o); }
int dir( const P &o, const P &a, const P &b ) { return sgn(X(o,a,b)); }

bool is_jiao( LL a, LL b, LL c, LL d ) { return max(a,b)>=min(c,d) && max(c,d)>=min(a,b); }
bool is_jiao( const P &a, const P &b, const P &c, const P &d ) {
    if ( !is_jiao(a.x,b.x,c.x,d.x) ) return 0;
    if ( !is_jiao(a.y,b.y,c.y,d.y) ) return 0;
    if ( dir(a,b,c)*dir(a,b,d)>0 ) return 0;
    if ( dir(c,d,a)*dir(c,d,b)>0 ) return 0;
    return 1;
}

const double pi=acos(-1);
double get_ang( const P &o, const P &a, const P &b ) {
    double da=(a-o).ang();
    double db=(b-o).ang();
    double d=db-da;
    while ( d<-pi ) d+=2*pi;
    while ( d>=pi ) d-=2*pi;
    return d;
}

int n;
bool good[N][N];
int dp[N][N];
bool vis[N][N];

int go( int l, int r ) {
    //printf("== %d, %d\n",l,r);
    if ( l+1==r ) return 1;
    if ( vis[l][r] ) return dp[l][r];
    vis[l][r]=1;
    LL ret=0;
    REP1(i,l+1,r-1) if ( good[l][i] && good[r][i] ) ret+=1LL*go(l,i)*go(i,r)%MOD;
    return dp[l][r]=ret%MOD;
}

int main() {
    RI(n);
    if ( n==3 ) return puts("1"),0;
    REP(i,n) p[i].read();
    p[n]=p[0];
    REP(i,n) REP1(j,i+2,n-1) {
        good[i][j]=good[j][i]=1;
        REP(k,n) if ( k!=i && k!=j && is_jiao(p[i],p[j],p[k],p[k]) ) {
            good[i][j]=good[j][i]=0;
            break;
        }
        if ( !good[i][j] ) continue;
        REP(k,n) if ( k!=i && (k+1)%n!=i && k!=j && (k+1)%n!=j && is_jiao(p[i],p[j],p[k],p[k+1]) ) {
            good[i][j]=good[j][i]=0;
            break;
        }
        if ( !good[i][j] ) continue;
        P mid{(p[i].x+p[j].x)/2,(p[i].y+p[j].y)/2};
        double s=0;
        REP(k,n) s+=get_ang(mid,p[k],p[k+1]);
        if ( fabs(s)<1 ) good[i][j]=good[j][i]=0;
    }
    REP(i,n) good[i][(i+1)%n]=good[(i+1)%n][i]=1;
    //REP(i,n) REP(j,n) if ( good[i][j] ) printf("%d, %d\n",i,j);
    int ans=go(0,n-1);
    printf("%d\n",ans);
    return 0;
}