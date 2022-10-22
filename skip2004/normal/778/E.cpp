#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 1010;
typedef long long ll;
const int mod = 998244353;
int rk[maxn][maxn];
int kth[maxn][maxn]; char s[maxn][maxn];
int val[maxn][maxn];
int cnt[maxn][maxn];
bool good[maxn][maxn];
char a[maxn];
int c[10], * c_val = c, n;

int dp[maxn][maxn];
int to[maxn][maxn];
int add[maxn][maxn];
inline bool up(int & x, int y) {
	return x < y ? x = y, 1 : 0;
}
inline int calc(int x) {
	int ans = 0;
	for(int i = 0;i < n;++i) {
		ll o = 0;
		for(int j = strlen(s[i]) - 1;j >= 0;--j) o = o * 10 + s[i][j] - 48;
		o += x;
		for(;o;o /= 10) ans += c[o % 10];
	}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> a >> n;
	std::reverse(a, a + strlen(a));
	const int N = 1001;
	static int last[maxn];
	for(int i = 0;i < n;++i) {
		cin >> s[i];
		std::reverse(s[i], s[i] + strlen(s[i]));
	}
	for(int i = 0;i < 10;++i) {
		cin >> c[i];
	}
	for(int i = 0;i < n;++i) {
		for(int j = 0;s[i][j] || a[j];++j) {
			val[i][j] = c[s[i][j] & 15];
			good[i][j] = 1;
		}
		kth[0][i] = i;
	}
	for(int i = 0;i <= N;++i) {
		int * b = kth[i + 1];
		for(int j = 0;j < n;++j) b[j] = j;
		std::sort(b, b + n, [&](int a, int b) {
			int sa = s[a][i] & 15, sb = s[b][i] & 15;
			return sa != sb ? sa > sb : last[a] < last[b];
		});
		for(int j = 0, now = -1;j < n;++j) {
			rk[b[j]][i] = now += !j || s[b[j]][i] != s[b[j - 1]][i] || last[b[j]] != last[b[j - 1]];
			cnt[b[j]][i] = j;
		}
		for(int j = 0;j < n;++j) {
			last[j] = rk[j][i];
		}
	}
	std::vector<char> list = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', };
	for(int i = N - 1;i >= 0;--i) {
		static const int high = strlen(a) - 1;
		for(const char c : (a[i] == '?' ? list : std::vector<char>{a[i]})) if(i != high || c != '0') {
			const int v = c & 15;
			int og = -1, sum = 0;
			for(int j = 0;j < n;++j) {
				const int k = kth[i][j];
				if(v || good[k][i]) sum += c_val[((s[k][i] & 15) + v) % 10];
				if((s[k][i] & 15) + v >= 10) up(og, cnt[k][i]);
			}
			for(int j = 0;j <= n;++j) {
				const int k = kth[i][j];
				if(up(dp[i][j], dp[i + 1][og + 1] + sum)) {
					to[i][j] = og + 1;
					add[i][j] = v;
				}
				if(v || good[k][i]) {
					sum -= c_val[((s[k][i] & 15) + v) % 10];
					sum += c_val[((s[k][i] & 15) + v + 1) % 10];
				} else {
					sum += c_val[1];
				}
				if((s[k][i] & 15) + v >= 9) up(og, cnt[k][i]);
			}
		}
	}
	cout << dp[0][0] << '\n';
}