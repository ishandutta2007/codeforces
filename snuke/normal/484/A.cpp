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
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,ll> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

ll ans, l, r;
void f(ll x) {
  if (x < l || x > r) return;
  if (pcnt(x) < pcnt(ans)) return;
  if (pcnt(x) == pcnt(ans) && x >= ans) return;
  //cout << ans << " " << x << endl;
  ans = x;
}

int main(){
  int q;
  scanf("%d",&q);
  rep(qi,q) {
    scanf("%I64d%I64d",&l,&r);
    ans = l;
    f(r);
    ll nl = l, nr = r;
    vi a, b;
    rep(i,61) { a.pb(nl&1); nl >>= 1;}
    rep(i,61) { b.pb(nr&1); nr >>= 1;}
    reverse(rng(a));
    reverse(rng(b));
    ll now = 0, x = 1;
    rep(i,60) x <<= 1;
    rep(i,61) {
      if (a[i] == b[i]) {
        now += x*a[i];
      } else {
        f(now+x-1);
        a[i] = 1;
        for(int j = i+1; j < 61; j++) a[j] = 0;
        now += x;
      }
      x >>= 1;
    }
    printf("%I64d\n",ans);
  }
  return 0;
}