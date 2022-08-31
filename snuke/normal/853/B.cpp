#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
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
typedef vector<vp> vvp;
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
const int MX = 1000005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n;
vl f(vvp& s) {
  vl d(MX,LINF);
  vi b(n,-1);
  ll sum = 0; int cnt = 0;
  rep(i,MX) {
    for (P p : s[i]) {
      int j = p.fi, c = p.se;
      if (b[j] == -1) {
        cnt++;
        sum += c;
        b[j] = c;
      } else {
        if (b[j] > c) {
          sum -= b[j]-c;
          b[j] = c;
        }
      }
    }
    if (cnt == n) {
      d[i] = sum;
    }
  }
  return d;
}

int main() {
  int m,w;
  scanf("%d%d%d",&n,&m,&w);
  vvp s(MX);
  vvp t(MX);
  rep(i,m) {
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if (b) {
      s[a].pb(P(b-1,d));      
    } else {
      t[MX-1-a].pb(P(c-1,d));      
    }
  }
  vl ds = f(s);
  vl dt = f(t);
  reverse(rng(dt));
  // cerr<<ds<<endl;cerr<<dt<<endl;
  ll ans = LINF;
  rep(i,MX-w-1) {
    // cerr<<i<<" "<<ds[i]+dt[i+w+1]<<endl;
    mins(ans, ds[i]+dt[i+w+1]);
  }
  if (ans == LINF) ans = -1;
  cout<<ans<<endl;
  return 0;
}