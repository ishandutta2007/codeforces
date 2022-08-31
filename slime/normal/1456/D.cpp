//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 5005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
int dp[maxn][maxn], sum[maxn][maxn];
#define int long long
int t[maxn], x[maxn];
int id[maxn], tr[maxn];
int n;
int qid(int k) {
	return lower_bound(tr + 1, tr + n + 1, k) - tr;
} 
const int inf = 2e9;
pi cal(int a, int b, int t) {
	t -= abs(b - a);
	if (t < 0) return mp(inf, -inf);
	else return mp(min(a, b) - t / 2, max(a, b) + t / 2);
}
#undef int
int main() {
	#define int long long
	cin >> n;
	vector<pi> cur;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> x[i], 
		cur.pb(mp(x[i], i));
	sort(cur.begin(), cur.end());
	for (int i = 0; i < n; i++)
		tr[i + 1] = cur[i].fi, 
		id[cur[i].se] = i + 1;
	dp[n + 1][0] = 1;
	for (int i = n; i >= 0; i--) {
		for (int j = 0; j <= n; j++) {
			if (i == n) dp[i][j] = 1;
			else {
				if (j <= i && j != 0) dp[i][j] = 0;
				else if (j >= i + 2) {
					if (abs(x[i + 1] - x[i]) <= t[i + 1] - t[i]) dp[i][j] = dp[i + 1][j];
					else dp[i][j] = 0;
				}
				else {
					int nx = i + 2;
					int np = x[i], nt = t[i], lst = -1;
					if (j == 0) nx = i + 1;
					else lst = t[i + 1];
					for (int e = nx; e <= n + 1; e++) {
						if (e != n + 1 && abs(x[e] - np) > t[e] - nt) break;
						if (dp[e][0]) {
							dp[i][j] = 1;
							break;
						}
						pi cur;
						if (lst == -1) cur = cal(np, x[e], t[e] - nt);
						else {
							pi u1 = cal(min(np + lst - nt, x[e] + t[e] - lst), x[e], t[e] - lst);
							pi u2 = cal(max(np - (lst - nt), x[e] - (t[e] - lst)), x[e], t[e] - lst);
							cur.fi = min(u1.fi, u2.fi);
							cur.se = max(u1.se, u2.se);
						}
						if (cur.fi <= cur.se) {
							cur.fi = qid(cur.fi);
							cur.se = qid(cur.se + 1) - 1;
							if (sum[e][cur.se] > sum[e][cur.fi - 1]) {
								dp[i][j] = 1;
								break;
							}
						}
						nt += abs(x[e] - np);
						np = x[e];
						if (lst != -1) nt = max(nt, lst);
						lst = t[e];
					}
				}
			//	cout << i << ' ' << j << ' ' << dp[i][j]<< endl;
			} 
		}
		for (int j = 1; j <= n; j++)
			if (dp[i][j])
				sum[i][id[j]]++;
		for (int j = 1; j <= n; j++)
			sum[i][j] += sum[i][j - 1];
	}
	if (dp[0][0]) cout << "YES" << endl;
	else cout << "NO" << endl; 
	return 0;
}