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
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
inline int in() { int x; scanf("%d", &x); return x; }
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 305, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

int l[MX], c[MX];

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}

vi d[MX];

// Eratosthenes' sieve
vector<int> ps; vector<bool> pf;
void sieve(int mx){
	pf.resize(mx+1); fill(rng(pf),true); pf[0] = pf[1] = false;
	for(ll i = 2; i <= mx; i++){
		if(!pf[i]) continue;
		ps.pb(i);
		for(ll j = i*i; j <= mx; j+=i) pf[j] = false;
	}
}
//

int dp[1<<10];

int main(){
  int n;
  cin >> n;
  rep(i,n) cin >> l[i];
  rep(i,n) cin >> c[i];
  sieve(100005);
  rep(i,n) {
    int x = l[i];
    for(int p : ps) {
      if (x%p) continue;
      while (x%p) x /= p;
      d[i].pb(p);
    }
    if (x != 1) d[i].pb(x);
  }
  int ans = INF;
  rep(ni,n) {
    vi a = d[ni];
    int m = a.size();
    rep(i,1<<m) dp[i] = INF;
    dp[(1<<m)-1] = c[ni];
    rep(j,ni) {
      int f = 0;
      rep(k,a.size()) {
        if (binary_search(rng(d[j]),a[k])) f |= 1<<k;
      }
      rep(k,1<<m) {
        if (dp[k] == INF) continue;
        mins(dp[k&f],dp[k]+c[j]);
      }
    }
    mins(ans,dp[0]);
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}