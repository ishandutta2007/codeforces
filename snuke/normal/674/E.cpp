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
#define dame { puts("0"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
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

const int MX = 500005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;
const int D = 90;

int n;
int p[MX];
double ans[MX];
double d[MX][D+1];

void up(int v) {
  double x = 1, pre = 1, tmp;
  rep(di,D) {
    int u = p[v];
    if (u == -1) break;
    x /= 2;
    tmp = d[u][di+1];
    d[u][di+1] /= (pre+1)/2;
    pre = tmp;
    x *= d[u][di+1];
    d[u][di+1] *= (d[v][di]+1)/2;
    ans[u] += x;
    v = u;
  }
}

int main() {
  int q; n = 1; p[0] = -1;
  scanf("%d",&q);
  rep(i,q+1)rep(j,D) d[i][j+1] = 1;
  rep(qi,q) {
    int ty, v;
    scanf("%d%d",&ty,&v); --v;
    if (ty == 1) {
      p[n] = v;
      v = n++;
      up(v);
    } else {
      printf("%.10f\n",ans[v]);
    }
  }
  return 0;
}