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
#include <random>
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
#define bn(x) ((1<<x)-1)
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
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n, m;
vvi a, b;
vi dp, p;

void f(int l, int r, int sl, int sr) {
  if (!(r-l)) return;
  int c = (l+r)>>1;
  int s = 0;
  dp[c] = INF;
  for (int i = sl; i < sr; ++i) if (i < c) {
    int now = p[i]+b[i+1][c];
    if (now < dp[c]) {
      dp[c] = now;
      s = i;
    }
  }
  f(l,c,sl,s+1);
  f(c+1,r,s,sr);
}

char is[10005];
int main() {
  scanf("%d%d\n",&n,&m);
  a = vvi(n,vi(n+1));
  rep(i,n) {
    fgets(is,10005,stdin);
    rrep(j,n) a[i][j] = is[j*2-2]-'0';
  }
  rep(i,n)rep(j,n) a[i][j+1] += a[i][j];
  b = vvi(n,vi(n+1));
  rep(l,n) {
    int now = 0;
    for (int r = l; r < n; ++r) {
      now += a[r][r]-a[r][l];
      b[l][r] = now;
    }
  }
  dp = vi(n);
  rep(i,n) dp[i] = b[0][i];
  rep(i,m-1) {
    p = vi(n,INF);
    swap(dp,p);
    f(0,n,0,n);
  }
  cout<<dp.back()<<endl;
  return 0;
}