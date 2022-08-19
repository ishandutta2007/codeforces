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
const int MX = 100005, INF = 1e9;
const ll LINF = 1e18;
const double eps = 1e-10;
#include <random>
random_device _rd;
mt19937 _mt(_rd());
inline int rnd(unsigned n) {
  unsigned res = _mt();
  if (res >= n) return rnd(n);
  return res;
}
inline int rnd(int l, int r) { return _mt()%(r-l+1)+l;}
double rnd() { return rnd(1e9)/1e9;}

int gen_p(int p) {
  double s = 0;
  int res = 0;
  while (s < 1) {
    s += -log(1-rnd())/p;
    ++res;
  }
  return res;
}
void poisson(vi& a, int p) {
  rep(i,sz(a)) {
    a[i] = gen_p(p);
  }
}
void uniform(vi& a, int p) {
  rep(i,sz(a)) {
    a[i] = rnd(0,p*2);
  }
}

int main() {
  int ts;
  scanf("%d",&ts);
  rep(ti,ts) {
    int n = 250;
    vi a(n);
    cin>>a;
    // int p = rnd(10,1000);
    // if (ti&1) poisson(a,p); else uniform(a,p);

    double av = 0;
    rep(i,n) av += a[i];
    av /= n;
    double s = 0;
    rep(i,n) {
      s += (a[i]-av)*(a[i]-av);
    }
    s /= n;
    // cerr<<a<<endl;
    // cerr<<av<<" "<<s<<" "<<s/av<<" "<<p<<endl;

    if (s/av < 2) puts("poisson");
    else puts("uniform");
    // assert((s/av < 2) == (ti&1));
  }
  return 0;
}