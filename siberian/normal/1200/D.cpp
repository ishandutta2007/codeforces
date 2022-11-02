#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2e3 + 10;

int n, k;
int table[MAXN][MAXN];

void read() {
	cin >> n >> k;
	//cout << n << " " << k << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char x;
			cin >> x;
			//cout << x;
			table[i][j] = table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1] + (x == 'B');
		}
		//cout << endl;
	}

	/*cout << "table = " << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << table[i][j] << " ";
		cout << endl;
	}*/
}

int get(int x1, int y1, int x2, int y2) {
	if (x1 > x2)
		return 0;
	if (y1 > y2)
		return 0;	
	return table[x2][y2] - table[x1 - 1][y2] - table[x2][y1 - 1] + table[x1 - 1][y1 - 1];
}

int ans;
int dp1[MAXN][MAXN], dp2[MAXN][MAXN];

bool check1(int j) {
	return get(1, j, n, j) == 0;
}

bool check1(int i, int j) {
	return get(1, j, i - 1, j) + get(i + k, j, n, j) == 0 && get(i, j, i + k - 1, j) > 0;
}

bool check2(int i) {
	return get(i, 1, i, n) == 0;
}

bool check2(int i, int j) {
	return get(i, 1, i, j - 1) + get(i, j + k, i, n) == 0 && get(i, j, i, j + k - 1) > 0;
}

void build1() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += check1(i);
	}

	for (int i = 1; i + k - 1 <= n; i++) {
		dp1[i][1] = cnt;
		for (int j = 1; j <= k; j++)
			dp1[i][1] += check1(i, j);
		for (int j = 2; j + k - 1 <= n; j++) {
			dp1[i][j] = dp1[i][j - 1] - check1(i, j - 1) + check1(i, j + k - 1);
		}
	}
}

void build2() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += check2(i);
	}

	for (int j = 1; j + k - 1 <= n; j++) {
		dp2[1][j] = cnt;
		for (int i = 1; i <= k; i++)
			dp2[1][j] += check2(i, j);
		for (int i = 2; i + k - 1 <= n; i++) {
			dp2[i][j] = dp2[i - 1][j] - check2(i - 1, j) + check2(i + k - 1, j);
		}
	}
}

void run() {
	build1();
	build2();
	/*cout << endl;
	cout << "dp1 = " << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "dp2 = " << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			chkmax(ans, dp1[i][j] + dp2[i][j]);
		}
	}
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