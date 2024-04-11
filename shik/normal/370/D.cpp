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

#define N 2013
char s[N][N];
int sx[N][N],sy[N][N];
int get( int x1, int y1, int x2, int y2 ) {
    if ( x1==x2 && y1==y2 ) return s[x1][y1]=='w';
    if ( x1==x2 ) return s[x1][y2+1]-s[x1][y1];
    if ( y1==y2 ) return s[x2+1][y1]-s[x1][y1];
    int ret=0;
    ret+=sx[x1][y2+1]-sx[x1][y1];
    ret+=sx[x2][y2+1]-sx[x2][y1];
    ret+=sy[x2][y1]-sy[x1+1][y1];
    ret+=sy[x2][y2]-sy[x1+1][y2];
    return ret;
}
int main() {
    int n,m;
    RII(n,m);
    REP(i,n) scanf("%s",s[i]);
    int x1=N,y1=N,x2=-1,y2=-1,wc=0;
    REP(i,n) REP(j,m) {
        if ( s[i][j]=='w' ) {
            wc++;
            x1=min(x1,i);
            x2=max(x2,i);
            y1=min(y1,j);
            y2=max(y2,j);
            sx[i][j+1]=sx[i][j]+1;
            sy[i+1][j]=sy[i][j]+1;
        } else {
            sx[i][j+1]=sx[i][j];
            sy[i+1][j]=sy[i][j];
        }
    }
    int d=max(x2-x1,y2-y1);
    REP(i,n) REP(j,m) if ( i+d<n && j+d<m ) {
        int c=get(i,j,i+d,j+d);
        if ( c!=wc ) continue;
        REP1(y,j,j+d) if ( s[i][y]=='.' ) s[i][y]='+';
        REP1(y,j,j+d) if ( s[i+d][y]=='.' ) s[i+d][y]='+';
        REP1(x,i,i+d) if ( s[x][j]=='.' ) s[x][j]='+';
        REP1(x,i,i+d) if ( s[x][j+d]=='.' ) s[x][j+d]='+';
        REP(x,n) puts(s[x]);
        return 0;
    }
    puts("-1");
    return 0;
}