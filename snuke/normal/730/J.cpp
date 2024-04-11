#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = 1; i <= n; ++i)
#define drep(i,n) for (int i = n-1; i >= 0; --i)
#define df(x) int x = in()
#define sz(x) int(x.size())
#define fi first
#define se second
#define rng(x) x.begin(),x.end()
#define pb push_back
#define dame {puts("No"); return 0;}
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
using namespace std;
inline int in() { int x; scanf("%d",&x); return x;}
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vp;
typedef vector<int> vi;

const int INF = 1001001001;

int dp[105][10105];

int main() {
	df(n);
	vi a(n), b(n);
	int sa = 0, sb = 0;
	rep(i,n) cin >> a[i], sa += a[i];
	rep(i,n) cin >> b[i], sb += b[i];
	rep(i,n+1)rep(j,sb+1) dp[i][j] = -INF;
	dp[0][0] = 0;
	rep(i,n) {
		drep(j,n)drep(k,sb) {
			maxs(dp[j+1][k+b[i]], dp[j][k]+a[i]);
		}
	}
	P ans(INF,INF);
	rep(i,n+1)rep(j,sb+1) if (j >= sa && dp[i][j] >= 0) mins(ans, P(i,-dp[i][j]));
	cout << ans.fi << " " << sa+ans.se << endl;
	return 0;
}