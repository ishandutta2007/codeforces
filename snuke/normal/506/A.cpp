#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cctype>
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

const int MX = 30000, D = 300*2, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

int x[MX+1], L;
int dp[MX+1][D];

int dfs(int p, int d) {
  if (p > MX) return 0;
  if (d < L || d > L+D) printf("%d %d\n",d,L);
  if (d < L || d > L+D) return 0;
  if (dp[p][d-L] != -1) return dp[p][d-L];
  int now = 0;
  if (d != 1) maxs(now,dfs(p+d,d-1));
  maxs(now,dfs(p+d,d));
  maxs(now,dfs(p+d,d+1));
  now += x[p];
  return dp[p][d-L] = now;
}

int main(){
  int n, d;
  scanf("%d%d",&n,&d);
  rep(i,n) {
    int a;
    scanf("%d",&a);
    x[a]++;
  }
  int sum = 0;
  for (L = d; L > 0; L--) {
    sum += L;
    if (sum > MX) break;
  }
  rep(i,MX+1)rep(j,D) dp[i][j] = -1;
  cout << dfs(0,d) << endl;
  return 0;
}