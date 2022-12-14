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
#include <numeric>
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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 505, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;


int n, m, b, mod;
int a[MX];
int dp[MX][MX];

int main(){
  scanf("%d%d%d%d",&n,&m,&b,&mod);
  rep(i,n) scanf("%d",&a[i]);
  rep(i,b+1) dp[0][i] = 1;
  rep(i,n) {
    int b3 = b+1-a[i];
    rep(j,m)rep(k,b3) {
      (dp[j+1][k+a[i]] += dp[j][k]) %= mod;
    }
    // rep(j,m)rep(k,b3)cout<<i<<" "<<j<<" "<<k<<" "<<dp[j][k]<<endl;
  }
  cout << dp[m][b] << endl;
  return 0;
}