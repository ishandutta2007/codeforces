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
typedef pair<ll,ll> P;
typedef pair<P,int> Q;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 200005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n, m;
ll l[MX], r[MX];
vector<Q> e;
// map<ll,int> xp;

int main() {
  scanf("%d%d",&n,&m);
  rep(i,n) {
    scanf("%I64d%I64d",&l[i],&r[i]);
  }
  rep(i,n-1) {
    e.pb(Q(P(r[i+1]-l[i],l[i+1]-r[i]),i));
  }
  // rep(i,e.size()) xp[e[i].fi.fi] = 0;
  // rep(i,e.size()) xp[e[i].fi.se] = 0;
  rep(i,m) {
    ll a;
    scanf("%I64d",&a);
    // xp[a] = 0;
    e.pb(Q(P(a,-1),i+1));
  }
  // int xn = 0:
  // for (auto it = xp.begin(); it != xp.end(); ++it) it->se = xn++;
  sort(rng(e));
  vi ans(n-1);
  set<P> s;
  for (Q p : e) {
    ll a = p.fi.fi;
    ll b = p.fi.se;
    int id = p.se;
    if (b == -1) {
      s.insert(P(a,id));
    } else {
      auto it = s.lower_bound(P(b,-1));
      if (it == s.end()) {
        puts("No");
        return 0;
      }
      ans[id] = it->se;
      s.erase(it);
    }
  }
  puts("Yes");
  priv(ans);
  return 0;
}