#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
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

int o;

ll c2(ll n) { return n*(n-1);}

int fl(vi& a) {
  int n = sz(a)+1;
  ll sm = suma(a);
  int mx = n/2+2;
  int l = -1, r = mx;
  while (l+1<r) {
    int c = (l+r)/2;
    int x = c*2+o;
    bool ok = true;
    if (sm <= c2(n)) {
      vi d = a; d.pb(x);
      sort(rng(d)); reverse(rng(d));
      ll s = sm, t = 0, k = 0;
      ll nx = x;
      stack<int> q;
      drep(i,n) {
        if (d[i] == nx) {
          nx = LINF;
        } else {
          s -= d[i];
        }
        t += d[i];
        q.push(d[i]);
        while (sz(q) && q.top() > i) {
          t -= q.top();
          ++k;
          q.pop();
        }
        // cerr<<x<<" "<<s<<" "<<c2(i) + t+k*i<<endl;
        if (s > c2(i) + t+k*i) ok = false;
      }
    } else ok = false;
    if (ok) r = c; else l = c;
  }
  return r*2+o;
}

int fr(vi& a) {
  int n = sz(a)+1;
  ll sm = suma(a);
  int mx = n/2+2;
  int l = -1, r = mx;
  while (l+1<r) {
    int c = (l+r)/2;
    int x = c*2+o;
    bool ok = true;
    if (sm+x <= c2(n)) {
      vi d = a; d.pb(x);
      sort(rng(d)); reverse(rng(d));
      ll s = sm+x, t = 0, k = 0;
      ll nx = x;
      stack<int> q;
      drep(i,n) {
        s -= d[i];
        if (d[i] == nx) {
          nx = LINF;
          ++k;
        } else {
          t += d[i];
          q.push(d[i]);
        }
        while (sz(q) && q.top() > i) {
          t -= q.top();
          ++k;
          q.pop();
        }
        // cerr<<x<<" "<<s<<" "<<c2(i) + t+k*i<<endl;
        if (s > c2(i) + t+k*i) ok = false;
      }
    } else ok = false;
    if (ok) l = c; else r = c;
  }
  return l*2+o;
}

int main() {
  int n;
  scanf("%d",&n);
  vi a(n);
  cin>>a;
  sort(rng(a));
  o = suma(a)&1;
  int l = fl(a);
  int r = fr(a);
  // cout<<l<<" "<<r<<endl;
  vi ans;
  for (int i = l; i <= r; i += 2) ans.pb(i);
  if (sz(ans) == 0) ans.pb(-1);
  cout<<ans<<endl;
  return 0;
}