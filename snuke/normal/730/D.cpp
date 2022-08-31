#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cctype>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = 1; i <= n; ++i)
#define drep(i,n) for (int i = n-1; i >= 0; --i)
#define df(x) int x = in()
#define sz(x) int(x.size())
#define fi first
#define se second
#define rng(x) x.begin(),x.end()
#define pb push_back
#define dame {puts("-1"); return 0;}
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
using namespace std;
inline int in() { int x; scanf("%d",&x); return x;}
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vp;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ll> vl;

const int MX = 100000;
const int INF = 1001001001;


int main() {
  df(n);
  ll r;
  scanf("%I64d", &r);
  vl as;
  ll ans = 0, w = 0, x = 0;
  vi ls(n), ts(n);
  rep(i,n) ls[i] = in();
  rep(i,n) ts[i] = in();
  rep(i,n) {
    int l = ls[i];
    int t = ts[i];
    if (l > t) dame;
    if (l <= w) {
      w -= l;
      x += l;
    } else {
      x += w;
      l -= w;
      t -= w;
      w = 0;
      t = l*2-t;
      if (t > 0) {
        x += (l-t)*2;
        ans += t/r;
        rep(i,t/r) {
          if (sz(as) > MX) break;
          as.pb(x+r*i);
        }
        x += t/r*r;
        if (t%r) {
          as.pb(x);
          w = r-t%r;
          ans++;
          x += t%r;
        }
      } else {
        x += l*2;
      }
    }
  }
  printf("%I64d\n", ans);
  if (ans <= MX) {
    rep(i,ans) printf("%I64d%c", as[i], i==ans-1?'\n':' ');
  }
	return 0;
}