#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define pb push_back
#define maxn 2019
#define maxs
#define maxnode
#define ls ch[o][0]
#define rs ch[o][1]
#define M 998244353
#define Hash
#define Base 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define mem(x, v) memset(x, sizeof(x), v)
using namespace std;

int n, k;
int a[maxn];

bool vis[maxn][maxn << 1];
int dp[maxn][maxn << 1];
int DP(int pos, int dd){
	if (pos == n + 1){
		if (dd > n) return 1;
		else return 0;
	}
	if (vis[pos][dd]) return dp[pos][dd];
	vis[pos][dd] = 1;
	int& ans = dp[pos][dd];
	if (a[pos + 1] == a[pos]) {
		return ans = (ll)k * DP(pos + 1, dd) % M; 
	}
	else {
		return ans = ((ll)DP(pos + 1, dd - 1) + DP(pos + 1, dd + 1) + (ll)(k - 2) * DP(pos + 1, dd)) % M;
	}
}

int main(){
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &a[i]); 
	a[n + 1] = a[1];
	printf("%d", DP(1, n));
	return 0;
}