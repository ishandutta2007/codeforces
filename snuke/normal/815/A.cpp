#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("-1"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
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
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;
typedef vector<string> vs;



int main() {
  int h,w;
  scanf("%d%d",&h,&w);
  vvi a(h,vi(w));
  rep(i,h)rep(j,w) scanf("%d",&a[i][j]);
  vs s = {"row", "col"};
  if (h < w) {
    vvi b(w,vi(h));
    swap(a,b);
    swap(h,w);
    rep(i,h)rep(j,w) a[i][j] = b[j][i];
    reverse(rng(s));
  }
  int l = 0;
  rep(i,h) if (a[l][0] > a[i][0]) l = i;
  vi r = a[l];
  vi c(h);
  rep(i,h) c[i] = a[i][0]-r[0];
  // cerr<<r<<endl;
  // cerr<<c<<endl;
  rep(i,h)rep(j,w) {
    if (r[j]+c[i] != a[i][j]) dame;
  }
  int sum = 0;
  rep(i,w) sum += r[i];
  rep(i,h) sum += c[i];
  printf("%d\n",sum);
  rep(i,w) {
    rep(k,r[i]) printf("%s %d\n", s[1].c_str(), i+1);
  }
  rep(i,h) {
    rep(k,c[i]) printf("%s %d\n", s[0].c_str(), i+1);
  }
  return 0;
}