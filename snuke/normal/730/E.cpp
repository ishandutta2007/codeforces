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
#define dame {puts("No"); return 0;}
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
using namespace std;
inline int in() { int x; scanf("%d",&x); return x;}
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vp;
typedef vector<int> vi;
typedef vector<string> vs;

const int MX = 3005;
const int INF = 1001001001;


int main() {
	df(n);
  vi a(n), d(n);
  vp p;
  rep(i,n) {
    cin >> a[i] >> d[i];
    p.pb(P(a[i],-i));
    p.pb(P(a[i]+d[i],-i));
  }
  sort(rng(p));
  vp s(n);
  rep(i,n) {
    s[i].fi = lower_bound(rng(p), P(a[i],-i))-p.begin();
    s[i].se = lower_bound(rng(p), P(a[i]+d[i],-i))-p.begin();
  }
  int ans = 0;
  rep(i,n)rep(j,i) {
    vp x;
    x.pb(P(s[i].fi,0));
    x.pb(P(s[i].se,1));
    x.pb(P(s[j].fi,2));
    x.pb(P(s[j].se,3));
    sort(rng(x));
    vi c;
    rep(k,4) c.pb(x[k].se);
    if (c[0] >= 2) rep(k,4) c[k] ^= 2;
    if (c[0]+c[1] == 1) continue;
    ans++;
    if (c == (vi){0,2,1,3} || c == (vi){1,3,0,2}) ans++;
  }
  cout << ans << endl;
	return 0;
}