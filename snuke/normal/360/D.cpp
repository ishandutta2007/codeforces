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
inline int in() { int x; scanf("%d",&x); return x;}
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 10005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
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

int n, m, p;
int a[MX], b;

ll ex(ll x, ll y) {
  if (!y) return 1;
  ll r = ex(x,y>>1);
  return r*r%p*(y&1?x:1)%p;
}

vi d;
vector<P> e;
map<int,int> mp;
int q;

void dfs(int i, int x, int y) {
  if (i == e.size()) {
    mp[x] = y;
    return;
  }
  int z = 1, mx;
  rep(j,e[i].se) z *= e[i].fi;
  mx = z;
  int sum = 0;
  rep(j,e[i].se+1) {
    int now = mx/z-sum;
    dfs(i+1,x*z,y*now);
    sum += now;
    z /= e[i].fi;
  }
}

int main(){
  scanf("%d%d%d",&n,&m,&p);
  rep(i,n) scanf("%d",&a[i]);
  rep(j,m) {
    int nb;
    scanf("%d",&nb);
    b = gcd(b,nb);
  }
  m = q = p-1;
  sieve(100005);
  for (int x : ps) {
    int c = 0;
    while (m%x == 0) {
      m /= x;
      ++c;
    }
    if (c) e.pb({x,c});
  }
  if (m != 1) e.pb({m,1});
  for (int i = 1; i*i <= q; ++i) {
    d.pb(i);
    if (i*i != q) d.pb(q/i);
  }
  sort(rng(d));
  set<int> s;
  rep(i,n) {
    int z = q;
    a[i] = ex(a[i],b);
    for (auto x : e) {
      rep(j,x.se) {
        int now = z/x.fi;
        if (ex(a[i],now) != 1) break;
        z = now;
      }
    }
    //printf("%d %d\n",a[i],z);
    s.insert(q/z);
  }
  dfs(0,1,1);
  //for (auto x : mp) printf("%d %d\n",x.fi,x.se);
  int ans = 0;
  for (int x : d) {
    bool ok = false;
    for (int y : s) {
      if (x%y == 0) ok = true;
      //printf("%d %d\n",x,y);
    }
    if (ok) ans += mp[x];
  }
  cout << ans << endl;
  return 0;
}