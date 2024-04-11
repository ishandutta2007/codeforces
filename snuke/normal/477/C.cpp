#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 2005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

string s, t;
int a[MX];
int dp[MX][MX];
int ans[MX];

int main(){
	cin >> s >> t;
  int n = s.size(), m = t.size();
  rep(i,n) a[i] = -1;
	rep(i,n) {
    if (s[i] != t[0]) continue;
    int j = i, k = 0;
    while (j < n && k < m) {
      if (s[j++] == t[k]) k++;
    }
    if (k == m) a[i] = j-i;
  }
  rep(i,n+1)rep(j,n+1) dp[i][j] = MX;
  dp[0][0] = 0;
  rep(i,n) {
    rep(j,n) {
      mins(dp[i+1][j],dp[i][j]);
      if (a[i] != -1) mins(dp[i+a[i]][j+1],dp[i][j]+(a[i]-m));
    }
  }
  rep(i,n+1) if (dp[n][i] < MX) ans[dp[n][i]] = i;
  rep(i,n) maxs(ans[i+1],ans[i]);
  rep(i,n+1) {
    ans[i] = min(ans[i],(n-i)/m);
    printf("%d",ans[i]);
    if (i == n) puts(""); else printf(" ");
  }
	
	return 0;
}