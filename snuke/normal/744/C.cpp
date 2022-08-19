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

const int D = 100;
int dp[1<<16][D];

int main() {
  int n;
  scanf("%d",&n);
  vi a(n),b(n),c(n);
  int cnt = 0;
  rep(i,n) {
    char ch;
    scanf(" %c",&ch);
    c[i] = ch=='R';
    scanf("%d%d",&a[i],&b[i]);
    cnt += c[i];
  }
  if (cnt > 8) {
    rep(i,n) swap(a[i],b[i]);
    rep(i,n) c[i] ^= 1;
    cnt = n-cnt;
  }
  int n2 = 1<<n;
  int n1 = n2-1;
  rep(i,n2)rep(j,D) dp[i][j] = -INF;
  dp[n1][0] = 0;
  drep(i,n2) {
    int sa = 0, sb = 0;
    rep(j,n) if (i>>j&1) sa += c[j];
    rep(j,n) if (i>>j&1) sb += !c[j];
    rep(j,n) if (i>>j&1) {
      int na = sa, nb = sb;
      na -= c[j];
      nb -= !c[j];
      mins(na,a[j]);
      mins(nb,b[j]);
      rep(k,D-na) {
        maxs(dp[i^1<<j][k+na], dp[i][k]+nb);
      }
    }
  }
  int ans = INF;
  int as = 0, bs = 0;
  rep(i,n) as += a[i];
  rep(i,n) bs += b[i];
  rep(i,D) {
    int now = max(as-i,bs-dp[0][i]);
    maxs(now,0);
    mins(ans,now);
  }
  ans += n;
  cout<<ans<<endl;
  return 0;
}