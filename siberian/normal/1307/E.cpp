#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
const int MOD = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) 
		a += MOD;
	return a;
}

int mul(int a, int b) {
	return (ll) a * b % MOD;
}

const int MAXN = 5e3 + 10;

int n, m;
int s[MAXN];

vector<int> a[MAXN];

void read() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}
}

int SZ[MAXN];

void build() {
	for (int i = 0; i < n; i++)
		SZ[s[i]]++;
	for (int i = 1; i <= n; i++) {
		sort(all(a[i]));
	}
}

int now[MAXN];
int ans, cnt;

bool check1(int cntR, int ind) {
	if (a[ind].size() < 1) return false;
	return a[ind][0] <= cntR;
}

bool check2(int cntL, int cntR, int ind) {
	if (a[ind].size() < 2) return false;
	return a[ind][0] <= cntL && a[ind][1] <= cntR;
}

pair<int, int> calc(int cntL, int cntR, int ind) {
	if (check2(cntL, cntR, ind)) {
		int ans = 2;
		int fans = 0;
		int haveL = 0;
		int haveR = 0;
		for (int i = 0; i < a[ind].size(); i++) {
			if (a[ind][i] <= cntL) haveL++;
			else if (a[ind][i] <= cntR) haveR++;
			else break;
		}
		fans = mul(haveL, haveL - 1);
		fans = add(fans, mul(haveL, haveR));
		return {ans, fans};
	}
	else if (check1(cntR, ind)) {
		int ans = 1;
		int fans = 0;
		for (int i = 0; i < a[ind].size(); i++) {
			if (a[ind][i] <= cntL) fans++;
			if (a[ind][i] <= cntR) fans++;
			else break;
		}
		return {ans, fans};
	}
	else {
		return {0, 1};
	}
}

bool smart_check2(int cntL, int cntR, int ind) {
	if (a[ind].size() < 2) return false;
	bool flag1 = false, flag2 = false;
	for (int i = 0; i < a[ind].size(); i++) {
		if (a[ind][i] == cntL) {
			flag1 = true;
			continue;
		}
		if (a[ind][i] <= cntR) {
			flag2 = true;
			continue;
		}
	}
	return flag1 && flag2;
}

bool smart_check1(int cntL, int ind) {
	if (a[ind].size() < 1) return false;
	for (int i = 0; i < a[ind].size(); i++)
		if (a[ind][i] == cntL)
			return true;
	return false;
}

pair<int, int> smart_calc(int cntL, int cntR, int ind) {
	if (smart_check2(cntL, cntR, ind)) {
		int ans = 2;
		int fans = 0;
		for (int i = 0; i < a[ind].size(); i++) {
			if (a[ind][i] == cntL) continue;
			if (a[ind][i] <= cntR) fans++;
			else break;
		}
		return {ans, fans};
	}
	else if (smart_check1(cntL, ind)) {
		return {1, 1};
	}
	else {
		return {0, 0};
	}
}

void run() {
	build();
	ans = 0, cnt = 1;
	
	for (int i = 0; i < n; i++) {
		int fans = 0, fcnt = 1;
		now[s[i]]++;
		if (a[s[i]].empty()) continue;
		for (int j = 1; j <= n; j++) {
			if (a[j].empty()) continue;
			int cntL = now[j];
			int cntR = SZ[j] - cntL;

			if (s[i] == j) {
				auto x = smart_calc(cntL, cntR, j);
				fans = add(fans, x.first);
				fcnt = mul(fcnt, x.second);	
			}
			else {
				if (cntL > cntR) swap(cntL, cntR);
				auto x = calc(cntL, cntR, j);
				fans = add(fans, x.first);
				fcnt = mul(fcnt, x.second);
			}
		}

		if (fans < ans) continue;
		if (fans > ans) {
			ans = fans;
			cnt = 0;
		}
		cnt = add(cnt, fcnt);
	}

	int fans = 0, fcnt = 1;	
	/*cout << "a = " << endl;
	for (int i = 1; i <= n; i++) {
		cout << "i = " << i << endl;
		for (int j = 0; j < a[i].size(); j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/
	//cout << endl;
	for (int i = 1; i <= n; i++) {
		if (a[i].empty()) continue;
		int Cnt = 0;
		for (int j = 0; j < a[i].size(); j++) {
			Cnt += a[i][j] <= SZ[i];
		}
		//cout << i << " " << Cnt << endl;
		if (Cnt > 0) {
			fans++;
			fcnt = mul(fcnt, Cnt); 
		}
	}
	//cout << fans << " " << fcnt << endl;
	//exit(0);
	if (fans < ans) return;
	if (fans > ans) {
		ans = fans;
		cnt = 0;
	}
	cnt = add(cnt, fcnt);
}

void write() {
	if (ans == 0) cnt = 1;
	cout << ans << " " << cnt << endl;
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