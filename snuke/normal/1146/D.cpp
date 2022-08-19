#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;
// arithmetic progression sum
// first:s, diffrence:d, length: n
ll asum(ll s, ll d, ll n) {
  return s*n + (n-1)*n/2*d;
}

#define bsf __builtin_ctzll
ll gcd(ll a, ll b) {
  // a = abs(a); b = abs(b);
  if (!a || !b) return a|b;
  int t = bsf(a|b); a >>= bsf(a);
  do { b >>= bsf(b); if (a > b) swap(a, b); b -= a;} while (b);
  return a << t;
}
ll lcm(ll x, ll y) { return x/gcd(x,y)*y;}
int dp[MX];

ll f(ll r, ll g, ll m) {
  r /= g;
  return asum(m+1,-g,r+1);
}

int main() {
  int m,a,b;
  scanf("%d%d%d",&m,&a,&b);
  rep(i,MX) dp[i] = INF;
  PQ(P) q;
  dp[0] = 0; q.push(P(0,0));
  while (sz(q)) {
    int d = q.top().fi;
    int v = q.top().se;
    q.pop();
    if (dp[v] != d) continue;
    {
      int u = v+a;
      if (u < MX) {
        int nd = max(d,u);
        if (dp[u] <= nd) continue;
        dp[u] = nd;
        q.push(P(nd,u));
      }
    }
    {
      int u = v-b;
      if (u >= 0) {
        int nd = max(d,u);
        if (dp[u] <= nd) continue;
        dp[u] = nd;
        q.push(P(nd,u));
      }
    }
  }
  ll ans = 0;
  int r = min(MX-3,m);
  rep(i,r+1) {
    if (dp[i] == INF) continue;
    ans += max(0,m-dp[i]+1);
  }
  int g = gcd(a,b);
  ans += f(m,g,m)-f(r,g,m);
  cout<<ans<<endl;
  return 0;
}