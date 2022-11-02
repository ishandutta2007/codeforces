#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2e3 + 10, MAXNUM = 10;
int n, k;
string a[MAXN];

void read() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

vector<string> num = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int get(string & s, int need) {
	int cnt = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == num[need][i]) continue;
		if (s[i] == '1') return -1;
		cnt++;
	} 
	return cnt;
}

bool dp[MAXN][MAXN];

void no() {
	cout << -1 << endl;
	exit(0);
}

void precalc() {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			dp[i][j] = false;
		}
	}
	dp[n][0] = true;

	for (int i = n - 1; i >= 0; i--) {
		for (int x = 0; x < MAXNUM; x++) {
			int need = get(a[i], x);
			if (need == -1) continue;
			for (int cnt = need; cnt <= k; cnt++) {
				dp[i][cnt] |= dp[i + 1][cnt - need];
			}
		}
	}
}

string ans;

void calc() {
	if (dp[0][k] == false) no();
	ans = "";
	for (int i = 0; i < n; i++) {
		for (int num = MAXNUM - 1; num >= 0; num--) {
			int need = get(a[i], num);
			if (need == -1) continue;
			if (need > k) continue;
			if (!dp[i + 1][k - need]) continue;
			ans += '0' + num;
			k -= need;
			break;
		}
	}
}

void run() {
	precalc();
	calc();
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}