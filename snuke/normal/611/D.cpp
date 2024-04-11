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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 5005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

// Mod int
const int mod = 1000000007;
struct mint{
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  mint operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
//

string s;
int n;
mint dp[MX][MX];
int d[MX][MX];

int main() {
  cin >> n >> s;
  s += '$';
  drep(i,n) {
    rep(j,i) {
      if (s[i] == s[j]) {
        int x = d[i+1][j+1];
        if (x < 0) x++;
        if (x > 0) x--;
        d[i][j] = x;
      } else if (s[i] < s[j]) {
        d[i][j] = -(i-j);
      } else d[i][j] = (i-j);
    }
  }
  rrep(i,n) if (s[i] != '0') dp[i][0] = 1;
  mint ans = 0;
  rrep(i,n) {
    if (s[i] == '0') continue;
    rep(j,i) {
      int l = j-(i-j);
      if (l >= 0 && d[j][l] <= 0) ++l;
      maxs(l,0);
      // cout<<i<<" "<<j<<" "<<l<<endl;
      mint now = 0;
      if (j) now = dp[j][j-1];
      if (l) now -= dp[j][l-1];
      // dp[i][j] += dp[j][l~j-1];
      dp[i][j] += now;
    }
    ans = 0;
    rep(j,n) ans += dp[i][j];
    rep(j,i) dp[i][j+1] += dp[i][j];
  }
  cout<<ans.x<<endl;
  return 0;
}