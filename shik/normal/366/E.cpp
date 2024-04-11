// TwT514 {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(int)(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset((x),0,(n)*sizeof(*x))
#define MS1(x,n) memset((x),-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}

#define N 2010
#define S 100010
int a[N][N],q[S],gx[10][4],gy[10][4];
int main() {
    int n,m,k,s;
    RII(n,m);
    RII(k,s);
    REP1(i,1,n) REP1(j,1,m) RI(a[i][j]);
    REP1(i,1,s) RI(q[i]);
    REP1(i,1,n) REP1(j,1,m) REP(ii,4) {
        int v=a[i][j];
        gx[v][ii]=i;
        gy[v][ii]=j;
    }
    REP1(i,1,n) REP1(j,1,m) {
        int v=a[i][j];
        if ( i+j<gx[v][0]+gy[v][0] ) gx[v][0]=i,gy[v][0]=j;
        if ( i+j>gx[v][1]+gy[v][1] ) gx[v][1]=i,gy[v][1]=j;
        if ( i-j<gx[v][2]-gy[v][2] ) gx[v][2]=i,gy[v][2]=j;
        if ( i-j>gx[v][3]-gy[v][3] ) gx[v][3]=i,gy[v][3]=j;
    }
    int ans=0;
    REP1(i,1,s-1) {
        int v1=q[i];
        int v2=q[i+1];
        REP(ii,4) REP(jj,4) {
            int x1=gx[v1][ii];
            int y1=gy[v1][ii];
            int x2=gx[v2][jj];
            int y2=gy[v2][jj];
            ans=max(ans,abs(x1-x2)+abs(y1-y2));
        }
    }
    printf("%d\n",ans);
    return 0;
}