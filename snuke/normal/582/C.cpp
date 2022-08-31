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
#define df(x) int x = in()
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

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}

vi d[MX];
int n, a[MX];

int main() {
  scanf("%d",&n);
  rep(i,n) scanf("%d",&a[i]);
  rrep(i,n-1) {
    d[gcd(i,n)].pb(i);
  }
  ll ans = 0;
  rep(s,n+1) if (sz(d[s])) {
    vi x(s);
    rep(j,n) maxs(x[j%s],a[j]);
    vi b(n);
    rep(j,n) if (x[j%s] <= a[j]) b[j] = 1;
    int si = -1;
    rep(j,n) if (!b[j]) {
      si = j;
      break;
    }
    // cout<<s<<" "<<ans<<endl;
    // priv(b);
    if (si == -1) {
      ans += (ll)sz(d[s])*n;
    } else {
      int ni = si;
      bool fst = true;
      int cnt = 0, sum = 0;
      priority_queue<int,vi,greater<int>> q;
      while (fst || ni != si) {
        fst = false;
        ni = (ni+1)%n;
        int c = 0;
        while (b[ni]) {
          ni = (ni+1)%n;
          c++;
        }
        if (c == 0) continue;
        q.push(c);
        sum += c;
        cnt++;
      }
      for (int l : d[s]) {
        while (sz(q)) {
          if (q.top() >= l) break;
          sum -= q.top(); q.pop();
          cnt--;
        }
        ans += sum-(ll)cnt*l+cnt;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}