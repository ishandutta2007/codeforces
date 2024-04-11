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
inline int getInt() { int x; scanf("%d",&x); return x;}
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



int main() {
  int h,w;
  scanf("%d%d",&h,&w);
  vvi a(h,vi(w));
  cin>>a;
  vi x(h), y(w);
  rep(i,h)rep(j,w) maxs(x[i], a[i][j]);
  rep(i,h)rep(j,w) maxs(y[j], a[i][j]);
  sort(rng(x));
  sort(rng(y));
  vvi ans(h,vi(w));
  queue<P> q;
  int ni = 0, nj = 0;
  for (int e = h*w; e >= 1; --e) {
    bool ex = false;
    if (sz(x) && x.back() == e) {
      ex = true;
      drep(j,nj) q.emplace(ni,j);
      ++ni;
      x.pop_back();
    }
    if (sz(y) && y.back() == e) {
      ex = true;
      drep(i,ni) q.emplace(i,nj);
      ++nj;
      y.pop_back();
    }
    if (ex) ans[ni-1][nj-1] = e; else {
      while (1) {
        int i = q.front().fi, j = q.front().se;
        q.pop();
        if (ans[i][j]) continue;
        ans[i][j] = e;
        break;
      }
    }
  }
  rep(i,h) cout<<ans[i]<<endl;
  return 0;
}