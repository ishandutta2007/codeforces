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

int n, m, L;
vp p;
vi s;

vi fl(int x) {
  vi res;
  int ca = 0, cb = 0;
  int ai = 0, bi = 0;
  rep(i,sz(p)) {
    int e = p[i].fi;
    if (p[i].se == 1) {
      ca++;
      while (bi < i) {
        if (p[bi].se == -1 && e-p[bi].fi <= x) break;
        if (p[bi].se == -1) cb--;
        ++bi;
      }
      if (i >= m) res.pb(cb);
    } else {
      cb++;
      while (ai < i) {
        if (p[ai].se == 1 && e-p[ai].fi <= x) break;
        if (p[ai].se == 1) ca--;
        ++ai;
      }
      if (i >= m) res.pb(ca);
    }
  }
  return res;
}

bool f(int x) {
  vi l = fl(x);
  reverse(rng(p));
  vi r = fl(x);
  reverse(rng(p)); reverse(rng(r));
  rep(i,m) l[i] = -l[i];
  rep(i,m) r[i]--;
  rep(i,m) if (p[i].se == -1) {
    swap(l[i],r[i]);
    l[i] = -l[i];
    r[i] = -r[i];
  }
  rep(i,m) {
    l[i] -= s[i];
    r[i] -= s[i];
  }
  int tl = -INF, tr = INF;
  rep(i,m) {
    maxs(tl,l[i]);
    mins(tr,r[i]);
  }
  rep(i,m) {
    if (tl <= -s[i] && -s[i] <= tr) return true;
  }
  return false;
}

vi fs() {
  vi res;
  int cnt = 0;
  rep(i,m) {
    res.pb(cnt);
    cnt += p[i].se;
  }
  return res;
}

int main() {
  scanf("%d%d",&n,&L);
  vi a, b;
  a = b = vi(n);
  cin>>a>>b;
  sort(rng(a));
  sort(rng(b));
  rep(i,n) {
    p.pb(P(a[i],-1));
    p.pb(P(b[i],1));
    p.pb(P(a[i]+L,-1));
    p.pb(P(b[i]+L,1));
  }
  sort(rng(p));
  m = n*2;
  s = fs();
  int l = -1, r = L;
  while (l+1<r) {
    int c = (l+r)>>1;
    if (f(c)) r = c; else l = c;
  }
  cout<<r<<endl;
  return 0;
}