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
#include <bitset>
#include <cassert>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("-1"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// const int MD = 135, C = 67;
const int MD = 67;
const int MX = 4005;
const int MK = 91;

int dp[2][MX][MD][MK];
int a[MX];
int sum(int l, int r) {
  return a[r]-a[l];
}

int n;
int dfs(int t, int l, int j, int k) {
  int& now = dp[t][l][j][k];
  if (now != -INF) return now;
  if (!t) {
    int r = (n-l)-j;
    if (r-l < k) return now = 0;
    maxs(now, -dfs(1,l+k,j,k)+sum(l,l+k));
    if (r-l > k) maxs(now, -dfs(1,l+k+1,j,k+1)+sum(l,l+k+1));
  } else {
    int r = (n-l)-j+k;
    if (r-l < k) return now = 0;
    maxs(now, -dfs(0,l,j,k)+sum(r-k,r));
    if (r-l > k) maxs(now, -dfs(0,l,j+1,k+1)+sum(r-k-1,r));
  }
  return now;
}

int main() {
  scanf("%d",&n);
  rrep(i,n) scanf("%d",&a[i]);
  rep(i,n) a[i+1] += a[i];
  rep(t,2)rep(i,n)rep(j,MD)rep(k,MK) dp[t][i][j][k] = -INF;
  cout<<dfs(0,0,0,1)<<endl;
  return 0;
}