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
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

// ll f(ll x) {
//   ll xx = x;
//   if (x == 0) return 0;
//   vi d;
//   while (x) {
//     d.pb(x&1);
//     x >>= 1;
//   }
//   reverse(rng(d));
//   ll res = 0;
//   // cout<<sz(d)<<endl;
//   rrep(i,sz(d)-1) {
//     res += (1ll<<((i+1)/2-1));
//   }
//   // vi e = d;
//   // reverse(rng(e));
//   // cout<<res<<endl;
//   ll now = 0;
//   rrep(i,(sz(d)+1)/2-1) {
//     now = now*2+d[i];
//   }
//   res += now;
//   // cout<<res<<endl;
//   {
//     int l = (sz(d)+1)/2-1;
//     int r = l+1;
//     if (sz(d)&1) r--;
//     // cout<<xx<<" : "<<l<<" "<<r<<endl;
//     while (l >= 0) {
//       if (d[l] != d[r]) {
//         if (d[l] < d[r]) break;
//         // cout<<xx<<endl;
//         res--;
//         break;
//       }
//       l--;
//       r++;
//     }
//   }
//   cout<<res<<endl;
//   return res;
// }

ll f(ll x) {
  if (x == 0) return 0;
  vi d;
  while (x) {
    d.pb(x&1);
    x >>= 1;
  }
  ll res = 0;
  reverse(rng(d));
  rrep(i,sz(d)-1) {
    res += i-1;
  }
  rrep(i,sz(d)-1) {
    if (d[i] == 0) break;
    res++;
  }
  int cnt = 0;
  rep(i,sz(d)) cnt += 1-d[i];
  if (cnt == 1) res++;
  return res;
}

int main() {
  ll a, b;
  cin >> a >> b;
  --a;
  ll ans = f(b)-f(a);
  cout<<ans<<endl;
  // rep(i,16)cout<<i<<" "<<f(i)<<endl;
  return 0;
}