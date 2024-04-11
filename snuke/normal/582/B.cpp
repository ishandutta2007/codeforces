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
#define df(x) int x = in()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 105, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n, t, a[MX];
int d[MX][MX];
map<int,int> x;

// Matrix
struct mat{
  typedef int TT;
  int h, w;
  vector<vector<TT> > d;
  mat(){}
  mat(int h, int w, TT v=0):h(h),w(w),d(h,vector<TT>(w,v)){}
  mat operator*(const mat& a)const{ // w = a.h
    mat res(h,a.w);
    rep(i,h)rep(k,w)rep(j,a.w)if (i <= k && k <= j) maxs(res.d[i][j],d[i][k]+a.d[k][j]);
    return res;
  }
  mat power(ll a){ // h = w
    if(a == 1){
      return (*this);
    }
    mat res = power(a/2);
    res = res*res;
    if(a&1) res = res*(*this);
    return res;
  }
};
//

int main() {
  scanf("%d%d",&n,&t);
  rep(i,n) scanf("%d",&a[i]);
  rep(i,n) x[a[i]] = 0;
  int m = 0;
  for (auto &p : x) p.se = m++;
  rep(i,n) a[i] = x[a[i]];
  mat d(m,m);
  rep(i,n) {
    vi dp(n);
    dp[i] = 1;
    for (int j = i+1; j < n; ++j) {
      for (int k = i; k < j; ++k) if (a[k] <= a[j] && dp[k]) maxs(dp[j],dp[k]+1);
    }
    rep(j,n) if (a[i] <= a[j]) maxs(d.d[a[i]][a[j]],dp[j]);
  }
  // rep(i,m) priv(d.d[i]);
  rep(i,m) {
    int mx = 0;
    rep(j,m) {
      maxs(mx,d.d[i][j]);
      d.d[i][j] = mx;
    }
  }
  mat e = d.power(t);
  int ans = 0;
  rep(i,m)rep(j,m) if (i <= j) maxs(ans,e.d[i][j]);
  cout<<ans<<endl;
  return 0;
}