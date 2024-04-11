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
typedef vector<ll> vl;
typedef vector<vl> vvl;
inline int in() { int x; scanf("%d",&x); return x;}

const int MX = 300005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

ll a[MX];

int main() {
  int n, k;
  scanf("%d%d",&n,&k);
  rep(i,n) scanf("%I64d",&a[i]);
  sort(a,a+n);
  ll sum = a[n-1]-a[0];
  a[n] = a[n-1];
  int m1, m2, n1, n2;
  m1 = n/k; m2 = m1+1;
  n1 = n%k; //if (n1 == 0) n1 = k;
  n2 = k-n1; swap(n1,n2);
  vvl dp(n1+1,vl(n2+1,0));
  rep(i,n1+1)rep(j,n2+1) {
    int p = i*m1+j*m2;
    if (i != n1) {
      ll ad = a[p+m1]-a[p+m1-1];
      maxs(dp[i+1][j], dp[i][j]+ad);
    }
    if (j != n2) {
      ll ad = a[p+m2]-a[p+m2-1];
      maxs(dp[i][j+1], dp[i][j]+ad);
    }
  }
  // cout<<m1<<" "<<m2<<" "<<n1<<" "<<n2<<" "<<dp[n1][n2]<<endl;
  ll ans = sum-dp[n1][n2];
  cout<<ans<<endl;
  return 0;
}