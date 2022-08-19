#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
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

// Binary Indexed Tree
struct bit {
  typedef int TT;
  int n; vector<TT> d;
  bit() {}
  bit(int mx): n(mx), d(mx) {}
  void add(int i, TT x=1) {
    for (++i;i<n;i+=i&-i) d[i] += x;
  }
  TT sum(int i) {
    TT x = 0;
    for (++i;i;i-=i&-i) x += d[i];
    return x;
  }
};
//
struct seg {
  v(bit) d;
  seg(int mx):d(4,bit(mx)){}
  void add(int i, int c, int x=1) {
    d[c].add(i,x);
  }
  int sum(int c, int l, int r) {
    int res = 0;
    if (r) res += d[c].sum(r-1);
    if (l) res -= d[c].sum(l-1);
    return res;
  }
};


char ins[50];

int main() {
  string s;
  cin>>s;
  int n = sz(s);
  vi ci(256);
  ci['A'] = 0;
  ci['C'] = 1;
  ci['G'] = 2;
  ci['T'] = 3;
  
  vvi ti(11);
  v(seg) t;
  rep(i,11)rep(j,i) {
    ti[i].pb(sz(t));
    t.pb(seg(n/i+2));
    for (int k = j; k < n; k += i) {
      t.back().add(k/i,ci[s[k]]);
    }
  }
  int q;
  scanf("%d",&q);
  rep(qi,q) {
    int ty;
    scanf("%d",&ty);
    if (ty == 1) {
      int i;
      char c;
      scanf("%d %c",&i,&c);
      --i;
      int pre = ci[s[i]];
      s[i] = c;
      int now = ci[s[i]];
      if (pre == now) continue;
      rrep(j,10) {
        t[ti[j][i%j]].add(i/j,pre,-1);
        t[ti[j][i%j]].add(i/j,now);
      }
    } else {
      int l,r;
      scanf("%d%d%s",&l,&r,ins);
      --l;
      string c = ins;
      int m = sz(c);
      int ans = 0;
      rep(i,m) {
        int now = ci[c[(i-l%m+m)%m]];
        int nl = (l-i+m-1)/m;
        int nr = (r-i+m-1)/m;
        // cerr<<l<<" "<<r<<" "<<i<<": "<<nl<<" "<<nr<<" "<<ans<<endl;
        ans += t[ti[m][i]].sum(now,nl,nr);
      }
      printf("%d\n",ans);
    }
  }
  return 0;
}