#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int n;
int t[35];

bool nuri[400][400];
// n, x, y, dir
bool used[31][400][400][8];

void indfs(int p,int x,int y,int dir);
inline void dfs(int p,int x,int y,int dir){
  if(!used[p][x][y][dir]){
    used[p][x][y][dir] = true;
    indfs(p,x,y,dir);
  }
}

int dx[8] = {0,1,1, 1, 0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1, 0, 1};
void indfs(int p,int x,int y,int dir){
  REP(i,t[p]){
    nuri[x][y]=true;
    if(i!=t[p]-1){
      x += dx[dir];
      y += dy[dir];
    }
  }
  if(p!=n-1){
    int nxtdir = (dir+1)%8;
    dfs(p+1,x+dx[nxtdir],y+dy[nxtdir],nxtdir);
        nxtdir = (dir+7)%8;
    dfs(p+1,x+dx[nxtdir],y+dy[nxtdir],nxtdir);
  }
}

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",t+i);
  dfs(0,200,200,0);
  int ans = 0;
  REP(i,400)REP(j,400)ans+=nuri[i][j];
  printf("%d\n",ans);
  // FORR(y,200-20,200+20){
  //   FOR(x,200-20,200+20)putchar(nuri[x][y]?'*':' ');
  //   puts("");
  // }
  return 0;
}