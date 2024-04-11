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
#define eb emplace_back
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
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
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
#define dame { puts("No"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;



int main() {
  int n;
  scanf("%d",&n);
  vvi a(n);
  vl s(n);
  map<ll,int> mp;
  rep(i,n) {
    int m;
    scanf("%d",&m);
    a[i] = vi(m);
    cin>>a[i];
    s[i] = suma(a[i]);
    for (int x : a[i]) mp[x] = i;
  }
  ll tot = suma(s);
  if (abs(tot)%n) dame;
  tot /= n;

  int n2 = 1<<n;
  vi d(n2,INF);
  rep(si,n) {
    for (int sx : a[si]) {
      int i = si;
      ll x = sx;
      int f = 0;
      while (1) {
        if (f>>i&1) break;
        f |= 1<<i;
        x = tot-(s[i]-x);
        if (!mp.count(x)) {
          i = -1;
          break;
        }
        i = mp[x];
      }
      if (i == si && x == sx) {
        d[f] = sx;
      }
    }
  }

  vi dp(n2,INF);
  dp[0] = 0;
  rep(i,n2) {
    for (int j = i; j; j = (j-1)&i) {
      if (dp[i^j] != INF && d[j] != INF) {
        dp[i] = d[j];
        break;
      }
    }
  }

  int ni = n2-1;
  if (dp[ni] == INF) dame;
  puts("Yes");
  vp ans(n);
  while (ni) {
    ll x = dp[ni];
    while (1) {
      int i = mp[x];
      if (~ni>>i&1) break;
      ni ^= 1<<i;
      x = tot-(s[i]-x);
      ans[mp[x]] = P(x,i);
    }
  }
  for (P p : ans) {
    cout<<p.fi<<" "<<p.se+1<<endl;
  }
  return 0;
}