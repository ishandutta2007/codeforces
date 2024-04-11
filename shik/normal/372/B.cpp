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

#define N 45
int aa[N][N],sa[N][N],sg[N][N][N][N];
bool good[N][N][N][N],g[N][N][N][N];
bool is_good( int x1, int y1, int x2, int y2 ) {
    return sa[x2][y2]-sa[x2][y1-1]-sa[x1-1][y2]+sa[x1-1][y1-1] == 0;
}
int main() {
    int n,m,q;
    RIII(n,m,q);
    REP1(i,1,n) REP1(j,1,m) scanf("%1d",aa[i]+j);
    REP1(i,1,n) REP1(j,1,m) sa[i][j]=sa[i][j-1]+sa[i-1][j]-sa[i-1][j-1]+aa[i][j];
    REP1(i,1,n) REP1(j,1,m) REP1(k,i,n) REP1(l,j,m) good[i][j][k][l]=is_good(i,j,k,l);
    REP1(i,1,n) REP1(j,1,m) REP1(k,1,n) REP1(l,1,m) g[i][j][k][l]=good[n-i+1][m-j+1][k][l];
    REP1(i,1,n) REP1(j,1,m) REP1(k,1,n) REP1(l,1,m) {
        int &me=sg[i][j][k][l];
        me=g[i][j][k][l];
        me+=sg[i-1][j][k][l];
        me+=sg[i][j-1][k][l];
        me+=sg[i][j][k-1][l];
        me+=sg[i][j][k][l-1];
        me-=sg[i-1][j-1][k][l];
        me-=sg[i-1][j][k-1][l];
        me-=sg[i-1][j][k][l-1];
        me-=sg[i][j-1][k-1][l];
        me-=sg[i][j-1][k][l-1];
        me-=sg[i][j][k-1][l-1];
        me+=sg[i-1][j-1][k-1][l];
        me+=sg[i-1][j-1][k][l-1];
        me+=sg[i-1][j][k-1][l-1];
        me+=sg[i][j-1][k-1][l-1];
        me-=sg[i-1][j-1][k-1][l-1];
    }

    while ( q-- ) {
        int a,b,c,d;
        RII(a,b);
        RII(c,d);
        a=n-a+1;
        b=m-b+1;
        int ans=sg[a][b][c][d];
        printf("%d\n",ans);
    }
    return 0;
}