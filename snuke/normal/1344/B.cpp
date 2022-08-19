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
typedef v(string) vs;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>
//const int di[] = {-1,0,1,-1,1,-1,0,1}, dj[] = {-1,-1,-1,0,0,1,1,1};

// Union find
struct uf {
  vi d;
  uf(){}
  uf(int mx):d(mx,-1){}
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);}
  int size(int x) { return -d[root(x)];}
  int operator[](int x) { return root(x);}
  int operator()(int x) { return size(x);}
};
//



int main() {
  int h,w;
  scanf("%d%d",&h,&w);
  vs s(h);
  cin>>s;
  rep(i,h) {
    int cnt = 0, pre = 0;
    rep(j,w) {
      if (s[i][j] == '#') {
        if (!pre) ++cnt;
        pre = 1;
      } else pre = 0;
    }
    if (cnt > 1) dame;
  }
  rep(j,w) {
    int cnt = 0, pre = 0;
    rep(i,h) {
      if (s[i][j] == '#') {
        if (!pre) ++cnt;
        pre = 1;
      } else pre = 0;
    }
    if (cnt > 1) dame;
  }
  uf t(h*w);
  rep(i,h)rep(j,w) {
    if (s[i][j] == '.') continue;
    rep(v,4) {
      int ni = i+di[v], nj = j+dj[v];
      if (ni<0||nj<0||ni>=h||nj>=w) continue;
      if (s[ni][nj] == '.') continue;
      t.unite(i*w+j, ni*w+nj);
    }
  }
  int ans = 0;
  rep(i,h)rep(j,w) {
    if (s[i][j] == '.') continue;
    int v = i*w+j;
    if (t.root(v) == v) ++ans;
  }

  vi ax(h), ay(w);
  rep(i,h)rep(j,w) {
    if (s[i][j] == '#') ax[i] = 1;
    if (s[i][j] == '#') ay[j] = 1;
  }
  rep(i,h) {
    bool ok = false;
    rep(j,w) {
      if (s[i][j] == '#') ok = true;
      if (!ay[j]) ok = true;
    }
    if (!ok) dame;
  }
  rep(j,w) {
    bool ok = false;
    rep(i,h) {
      if (s[i][j] == '#') ok = true;
      if (!ax[i]) ok = true;
    }
    if (!ok) dame;
  }
  cout<<ans<<endl;
  return 0;
}