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



int main() {
  int n,m;
  cin>>n>>m;
  n *= 2;
  vi d(n);
  cin>>d;
  set<P> s;
  rep(i,n) s.insert(P(d[i],i));

  vp p(m);
  vi pa(n,-1);
  rep(i,m) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    p[i] = P(a,b);
    pa[a] = b;
    pa[b] = a;
  }
  int t;
  cin>>t;
  --t;
  while (sz(s)) {
    if (t) {
      int a;
      cin>>a;
      --a;
      s.erase(P(d[a],a));
      if (pa[a] != -1) {
        int b = pa[a];
        cout<<b+1<<endl;
        s.erase(P(d[b],b));
        t ^= 1;
      }
    } else {
      while (sz(p)) {
        int a = p.back().fi;
        int b = p.back().se;
        p.pop_back();
        if (s.count(P(d[a],a))) {
          s.erase(P(d[a],a));
          s.erase(P(d[b],b));
          if (d[a] < d[b]) swap(a,b);
          cout<<a+1<<endl;
          cin>>b;
        }
      }
      if (!sz(s)) break;
      auto it = s.rbegin();
      int a = it->se;
      cout<<a+1<<endl;
      s.erase(P(d[a],a));
    }
    t ^= 1;
  }
  return 0;
}