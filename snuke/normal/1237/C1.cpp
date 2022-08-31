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
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

multiset<int> s;
map<int,multiset<int>> sx;
map<P,multiset<int>> sy;
map<T,int> mp;

int main() {
  int n;
  scanf("%d",&n);
  vt p;
  rep(i,n) {
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    s.insert(x);
    sx[x].insert(y);
    sy[P(x,y)].insert(z);
    p.eb(x,y,z);
    mp[T(x,y,z)] = i;
  }
  auto get = [&](int x, int y, int z) {
    return mp[T(x,y,z)];
    // return lower_bound(rng(p), T(x,y,z)) - p.begin();
  };
  auto use = [&](int x, int y, int z) {
    s.erase(s.find(x));
    sx[x].erase(sx[x].find(y));
    sy[P(x,y)].erase(sy[P(x,y)].find(z));
  };
  auto nxt = [&](int y, int z) {
    int x = *(s.begin());
    {
      auto it = sx[x].lower_bound(y);
      if (it == sx[x].end()) --it;
      y = *it;
    }
    {
      auto& t = sy[P(x,y)];
      auto it = t.lower_bound(z);
      if (it == t.end()) --it;
      z = *it;
    }
    use(x,y,z);
    return get(x,y,z);
  };
  rep(i,n/2) {
    int a = nxt(0,0);
    int x,y,z;
    tie(x,y,z) = p[a];
    int b = nxt(y,z);
    printf("%d %d\n",a+1,b+1);
  }
  return 0;
}