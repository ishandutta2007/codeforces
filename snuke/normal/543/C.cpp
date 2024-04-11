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
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n, m;
string s[20];
int a[20][20];
int dp[1<<20];
int x[1<<20];

int main(){
  cin >> n >> m;
  rep(i,n) cin >> s[i];
  rep(i,n)rep(j,m) cin >> a[i][j];
  int n2 = 1<<n;
  rep(i,n2) dp[i] = INF;
  dp[0] = 0;
  rep(i,m){
    //*
    rep(j,n) x[1<<j] = a[j][i];
    /*
    rep(j,n2) {
      int k = j&-j;
      if (j == k) continue;
      x[j] = x[j^k] + x[k];
    }//*/
    rep(j,n2) {
      for (int k = j;k;) {
        int f = k&-k;
        mins(dp[j],dp[j^f]+x[f]);
        k ^= f;
      }
    }
    rep(c,26) {
      int f = 0, d = 0, l = 0;
      rep(j,n) {
        if (s[j][i] == 'a'+c) {
          f |= 1<<j;
          d += a[j][i];
          maxs(l,a[j][i]);
        }
      }
      if (!f) continue;
      d -= l;
      rep(j,n2) mins(dp[j|f],dp[j]+d);
    }
  }
  cout << dp[n2-1] << endl;
  return 0;
}