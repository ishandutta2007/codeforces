#include <vector>
#include <iostream>
using namespace std;
const int limit = 100000;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int gcdplusplus(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	return gcd(a, b);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	vector<int> d(limit + 1);
	for (int i = 1; i <= limit; ++i) {
		for (int j = i; j <= limit; j += i) {
			++d[j];
		}
	}
	for (int i = 0; i < Q; ++i) {
		int A, B, C;
		cin >> A >> B >> C;
		vector<int> g(8);
		for (int j = 1; j < 8; ++j) {
			g[j] = -1;
			if (j & 1) g[j] = gcdplusplus(g[j], A);
			if (j & 2) g[j] = gcdplusplus(g[j], B);
			if (j & 4) g[j] = gcdplusplus(g[j], C);
		}
		vector<string> perm = { "abc", "acb", "bac", "bca", "cab", "cba" };
		int ans = 0, ans12 = 0, ans23 = 0, ans31 = 0, ans123 = 0;
		for (int i = 1; i < 64; ++i) {
			int abit = 0, bbit = 0, cbit = 0, flag = 0;
			for (int j = 0; j < 6; ++j) {
				if ((i >> j) & 1) {
					abit |= 1 << perm[j].find('a');
					bbit |= 1 << perm[j].find('b');
					cbit |= 1 << perm[j].find('c');
					flag ^= 1;
				}
			}
			int sub = d[g[abit]] * d[g[bbit]] * d[g[cbit]];
			int sub12 = d[g[abit | bbit]] * d[g[cbit]];
			int sub23 = d[g[bbit | cbit]] * d[g[abit]];
			int sub31 = d[g[cbit | abit]] * d[g[bbit]];
			int sub123 = d[g[abit | bbit | cbit]];
			if (flag) ans += sub, ans12 += sub12, ans23 += sub23, ans31 += sub31, ans123 += sub123;
			else ans -= sub, ans12 -= sub12, ans23 -= sub23, ans31 -= sub31, ans123 -= sub123;
		}
		int final_ans = (ans + ans12 + ans23 + ans31 + ans123 * 2) / 6;
		cout << final_ans << '\n';
	}
	return 0;
}