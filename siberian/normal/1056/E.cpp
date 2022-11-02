#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

string s, t;
int n, m;
void read() {
	cin >> s >> t;
	n = s.size();
	m = t.size();
}

mt19937 rnd(time(0));

const int MOD = 1e9 + 7, p = 179 + rnd() % (int) 1e7;
const int MAXN = 1e6 + 10;
int pows[MAXN], h[MAXN];

int mul(int a, int b) {
	return a * b % MOD;
}

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

void build() {
	pows[0] = 1;
	for (int i = 1; i < MAXN; i++)
		pows[i] = mul(pows[i - 1], p);
	for (int i = 1; i <= m; i++) {
		h[i] = add(mul(h[i - 1], p), t[i - 1]);
	}
}

int get(int l, int r) {
	return sub(h[r], mul(h[l - 1], pows[r - l + 1]));
}

int ans;

void run() {
	build();

	int cnt_zero = 0, cnt_one = 0;
	for (auto i : s) {
		if (i == '0')
			cnt_zero++;
		else if (i == '1')
			cnt_one++;
	}

	//cout << cnt_zero << " " << cnt_one << endl;
	//cout << endl;

	ans = 0;

	for (int r0 = 1; r0 <= m; r0++) {
		int r1 = (m - r0 * cnt_zero) / cnt_one;
		if (r1 <= 0 || cnt_zero * r0 + cnt_one * r1 != m)
			continue;
		//cout << r0 << " " << r1 << endl;
		int pos = 1;
		int hash0 = -1, hash1 = -1;
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				int x = get(pos, pos + r0 - 1);
				if (hash0 == -1) {
					hash0 = x;
				}
				else if (hash0 != x) {
					flag = true;
				}
				pos += r0;
			}
			else if (s[i] == '1') {
				int x = get(pos, pos + r1 - 1);
				if (hash1 == -1) {
					hash1 = x;
				}
				else if (hash1 != x) {
					flag = true;
				}
				pos += r1;
			}
		}
		//cout << "pos = " << pos << endl;
		//cout << hash0 << " " << hash1 << endl;
		if (hash0 == hash1) 
			continue;
		if (flag)
			continue;
		ans++;
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