#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 42;
bool dp[N][N][N][N], f[N][N][N][N];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	srand(clock());

	int t;
	cin >> t;
	while (t --) {
		int n, a, b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		memset(f, 0, sizeof(f));
		memset(dp, 0, sizeof(dp));
		dp[0][0][0][0] = 1;
		s = "0" + s;
		vector<int> pa(42, 0), pb(42, 0);
		pa[0] = pb[0] = 1;
		for (int i = 1; i <= n; i ++) 
			pa[i] = pa[i-1] * 10 % a, pb[i] = pb[i-1] * 10 % b;

		for (int i = 0; i < n; i ++) {
			for (int r = 0; r <= i; r ++) {
				for (int x = 0; x < a; x ++)
					for (int y = 0; y < b; y ++) {
						if (dp[i][r][x][y]) {
							//printf("dp[%d][%d][%d][%d]\n", i,r,x,y);
							if (i==n) continue;
							dp[i+1][r+1][(x + pa[r] * (s[i+1] - '0'))%a][y] = 1;
							f[i+1][r+1][(x + pa[r] * (s[i+1] - '0'))%a][y] = 1;
							dp[i+1][r+0][x][(y + pb[i-r] * (s[i+1] - '0'))%b] = 1;
						}
					}
			}
		}

		pair<int,int> bst = {1000,-1};
		for (int i = 1; i < n; i ++) {
			if (dp[n][i][0][0]) {
				bst = min(bst, {abs(i-(n-i)), i});
			}
		}
		//cout << bst.first << " " << bst.second << "\n";
		if (bst.second == -1) cout << -1 << "\n";
		else {
			int r = bst.second, r2 = n - bst.second;
			int x = 0, y = 0;
			string ans = "";
			int p = n;
			while (p > 0) {
				assert(dp[p][r][x][y]);
				//printf("# %d %d %d %d\n", p, r, x, y);
				if (f[p][r][x][y]) {
					ans += "R";  r --; x = ((x - pa[r] * (s[p] - '0')) % a + a) % a; p--;
				} else {
					ans += "B"; r2 --; y = ((y - pb[r2] * (s[p] - '0')) % b + b) % b; p--;
				}
			}
			//reverse(ans.begin(), ans.end());
			cout << ans << "\n";
		}
	}
}