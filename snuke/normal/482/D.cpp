#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

// Mod int
const int mod = 1000000007;
struct mint{
	ll x;
	mint():x(0){}
	mint(ll x):x(x){}
	mint operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
	mint operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
	mint operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
	mint operator+(const mint& a)const{ return mint(*this) += a;}
	mint operator-(const mint& a)const{ return mint(*this) -= a;}
	mint operator*(const mint& a)const{ return mint(*this) *= a;}
};
//

vi to[MX];
mint dp[MX][2];
mint l[2], r[2], e[2], o[2], p[2];

void dfs(int v) {
  rep(i,to[v].size()) dfs(to[v][i]);
  rep(i,2) l[i] = r[i] = e[i] = o[i] = 0;
  l[0] = 1;
  rep(i,to[v].size()) {
    int u = to[v][i];
    rep(j,2) p[j] = l[j];
    rep(j,2) l[j] = p[j]+p[j]*dp[u][0]+p[j^1]*dp[u][1];
  }
  r[0] = 1;
  drep(i,to[v].size()) {
    int u = to[v][i];
    rep(j,2) p[j] = r[j];
    rep(j,2) r[j] = p[j]+p[j]*dp[u][0]+p[j^1]*dp[u][1];
  }
  e[0] = 1;
  rep(i,to[v].size()) {
    int u = to[v][i];
    rep(j,2) p[j] = e[j];
    e[0] = p[0]+p[0]*dp[u][0];
  }
  o[0] = 1;
  rep(i,to[v].size()) {
    int u = to[v][i];
    rep(j,2) p[j] = o[j];
    o[0] = p[0]+p[1]*dp[u][1];
    o[1] = p[1]+p[0]*dp[u][1];
  }
  dp[v][1] = l[0]+r[0]-e[0];
  dp[v][0] = l[1]+r[1]-o[1];
}

int main(){
  int n;
  scanf("%d",&n);
  rrep(i,n-1) {
    int a;
    scanf("%d",&a);
    to[a-1].pb(i);
  }
  dfs(0);
  //rep(i,n) printf("%d : %I64d %I64d\n", i, dp[i][0].x, dp[i][1].x);
  cout << (dp[0][0]+dp[0][1]).x << endl;
  
  return 0;
}