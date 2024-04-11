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
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 200005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n;
int a[MX];

// Union find
struct uf{
  vector<int> d;
  uf(){}
  uf(int mx):d(mx,-1){}
  int root(int x){
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  void unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y) return;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
  }
};
//

int d[MX];

int main(){
  scanf("%d",&n);
  rep(i,n) scanf("%d",&a[i]);
  vector<P> p(n);
  rep(i,n) {
    p[i] = P(-a[i],i);
  }
  sort(rng(p));
  uf t(n);
  int now = 1;
  rep(i,n) {
    int x = p[i].se;
    if (x && a[x-1] >= a[x]) t.unite(x-1,x);
    if (x+1 < n && a[x+1] >= a[x]) t.unite(x+1,x);
    maxs(now,-t.d[t.root(x)]);
    maxs(d[now],a[x]);
  }
  for (int i = n; i >= 1; --i) maxs(d[i-1],d[i]);
  vi ans;
  rrep(i,n) ans.pb(d[i]);
  priv(ans);
  return 0;
}