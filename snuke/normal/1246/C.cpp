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
const int MX = 2005;
typedef v(string) vs;

// Mod int
const int mod = 1000000007;
// const int mod = 998244353;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
typedef vector<mint> vm;
//

mint dp[MX][MX][2];
int cnt0[MX][MX];
int cnt1[MX][MX];

int main() {
  int h,w;
  scanf("%d%d",&h,&w);
  if (h == 1 && w == 1) {
    cout<<1<<endl;
    return 0;
  }
  vs s(h);
  cin>>s;
  dp[0][0][0] = 1;
  dp[0][0][1] = 1;
  rep(i,h)rep(j,w) cnt0[i][j] = cnt1[i][j] = s[i][j]=='R';
  drep(i,h)drep(j,w-1) cnt0[i][j] += cnt0[i][j+1];
  drep(i,h-1)drep(j,w) cnt1[i][j] += cnt1[i+1][j];
  rep(i,h)rep(j,w) {
    bool fst = P(i,j)==P(0,0);
    {
      mint now = dp[i][j][0];
      if (!fst) {
        int nj = j+1;
        if (nj < w) {
          dp[i][nj][0] += now;
        }
      }
      {
        int ni = i+1;
        if (ni < h) {
          dp[ni][j][1] += now;
          int cnt = cnt1[ni][j];
          int r = h-cnt;
          dp[r][j][1] -= now;
        }
      }
    }
    {
      mint now = dp[i][j][1];
      {
        int nj = j+1;
        if (nj < w) {
          dp[i][nj][0] += now;
          int cnt = cnt0[i][nj];
          int r = w-cnt;
          dp[i][r][0] -= now;
        }
      }
      if (!fst) {
        int ni = i+1;
        if (ni < h) {
          dp[ni][j][1] += now;
        }
      }
    }
    // cerr<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
  }
  mint ans = dp[h-1][w-1][0];
  ans += dp[h-1][w-1][1];
  cout<<ans<<endl;
  return 0;
}