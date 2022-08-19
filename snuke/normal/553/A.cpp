#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

// Mod int
const int mod = 1000000007;
struct mint;
mint ex(mint a, ll tms);
struct mint{
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  mint operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator/=(const mint& a){ (x*=ex(a,mod-2).x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  mint operator/(const mint& a)const{ return mint(*this) /= a;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
mint ex(mint a, ll tms){
  if(!tms) return 1;
  mint res = ex(a,tms/2);
  res *= res;
  return (tms&1)?res*a:res;
}
struct comb{
  vector<mint> f, g;
  comb(){}
  comb(int mx):f(mx+1),g(mx+1){
    f[0] = 1;
    rrep(i,mx) f[i] = f[i-1]*i;
    g[mx] = ex(f[mx],mod-2);
    for(int i=mx;i>0;i--) g[i-1] = g[i]*i;
  }
  mint c(int a, int b){
    if (a < b) return 0;
    return f[a]*g[b]*g[a-b];
  }
};
//

int main() {
  int n;
  cin >> n;
  comb c(2005);
  mint ans = 1;
  int s = 0;
  rep(i,n) {
    int a;
    cin >> a;
    s += a;
    ans *= c.c(s-1,a-1);
  }
  cout<<ans.x<<endl;
  return 0;
}