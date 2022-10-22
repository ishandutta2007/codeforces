#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 3030;
int n, s, m, k;
typedef std::pair<int, int> pr;
pr vec[maxn];
int a[maxn], b[maxn];
int ok[maxn];

int dp[maxn][maxn];

inline void up(int & x, int y) 
{
	if(x < y)
	{
		x = y;
	}
}
inline int can(int k) {
	for(int i = 1;i <= n;++i) {
		ok[i] = (a[i] <= k) + ok[i - 1];
	}
	for(int i = 0;i <= m;++i) {
		for(int j = 0;j <= n;++j) {
			dp[i][j] = -1e9;
		}
	}
	dp[0][0] = 0;
	for(int i = 0;i < m;++i) {
		int idx = 0, max = 0;
		for(int j = 0;j <= n;++j) {
			up(dp[i + 1][j], dp[i][j]);
			up(dp[i][j + 1], dp[i][j]);
			for(;idx < s && vec[idx + 1].first <= j + 1;++idx)
				up(max, vec[idx + 1].second);
			up(dp[i + 1][max], dp[i][j] + ok[max] - ok[j]);
		}
	}
	return * std::max_element(dp[m], dp[m] + n + 1);
}

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> s >> m >> k;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	for(int i = 1;i <= s;++i) {
		cin >> vec[i].first >> vec[i].second;
	}
	std::sort(vec + 1, vec + s + 1);
	std::sort(b + 1, b + n + 1);
	int L = 0, R = n;
	b[++R] = 2e9;
	for(;L + 1 != R;) {
		int mid = L + R >> 1;
		if(can(b[mid]) >= k) R = mid;
		else L = mid;
	}
	cout << (R == n + 1 ? -1 : b[R]) << '\n';
}