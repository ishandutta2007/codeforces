#include<bits/stdc++.h>
typedef double db;
int tc, n;
const db inf = 1. / 0;
const db eps = 1e-6;
db dp[1010][105], c, T;
inline void down(db & x, db y) { if(x > y) x = y; }
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	using std::cin;
	using std::cout;
	cin >> tc;
	for(;tc--;) {
		cin >> n >> c >> T;
		std::vector<std::pair<int, int>> vec(n);
		int sp = 0;
		for(int i = 0;i < n;++i) {
			cin >> vec[i].first >> vec[i].second;
			sp += vec[i].second;
		}
		sort(vec.begin(), vec.end());
		for(int i = 0;i <= sp;++i) for(int j = 0;j <= n;++j)
			dp[i][j] = inf;
		sp = 0, dp[0][0] = 0;
		for(int i = 0;i < n;++i) {
			int a = vec[i].first, score = vec[i].second, now = i + 1;
			for(int i = sp += score;i >= score;--i) 
				for(int cnt = now;cnt >= 1;--cnt)
					down(dp[i][cnt], dp[i - score][cnt - 1] / 0.9 + a);
		}
		int ans = 0;
		for(int i = sp;i >= 0;--i) {
			for(int cnt = 0;cnt <= n;++cnt) if(dp[i][cnt] != inf) {
				const std::function<db(db)> fc = [&](db x) {
					return dp[i][cnt] / 0.9 / (1 + x * c) + x + 10 * cnt; 
				};
				db l = 0, r = T;
				for(int c = 0;c <= 50;++c) {
					db mid = (l + r) / 2;
					if(fc(mid - eps) < fc(mid)) r = mid;
					else l = mid;
				}
				if(fc(l) <= T + 0.0005) {
					ans = i;
					goto output;
				}
			}
		}
		output:
		cout << ans << '\n';
	}
}