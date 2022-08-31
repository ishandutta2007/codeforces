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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("0"); return 0;}
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
{for(T&x:v)i>>x;return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;for(T&x:v)s<<' '<<x;return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}

const int MX = 200005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n, m, a, b, q;
int s[MX];
// Binary Indexed Tree
struct bit {
  typedef int TT;
  vector<TT> d; int n;
  bit() {}
  bit(int mx): n(mx), d(mx) {}
  void add(int i, TT x=1) {
    for (++i;i<n;i+=i&-i) d[i] += x;
  }
  TT sum(int i) {
    TT x = 0;
    for (++i;i;i-=i&-i) x += d[i];
    return x;
  }
};
//

int main() {
  scanf("%d%d%d%d%d",&n,&m,&a,&b,&q);
  bit d1(MX), d2(MX);
  rep(qi,q) {
    int ty;
    scanf("%d",&ty);
    if (ty == 1) {
      int x, p;
      scanf("%d%d",&p,&x);
      int ps = s[p]; s[p] += x;
      {
        int px = min(ps,b);
        int nx = min(s[p],b);
        d1.add(p,nx-px);
      }
      {
        int px = min(ps,a);
        int nx = min(s[p],a);
        d2.add(p,nx-px);
      }
    } else {
      int p;
      scanf("%d",&p);
      int ans = d1.sum(p-1)+(d2.sum(n)-d2.sum(p+m-1));
      printf("%d\n", ans);
    }
  }
  return 0;
}