#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int M = 998244353;

int add(int a, int b) {
	return a + b < M ? a + b : a + b - M;
}

int sub(int a, int b) {
	return a - b >= 0 ? a - b : a - b + M;
}

int mul(int a, int b) {
	return 1ll * a * b % M;
}

int pw(int a, int n) {
	int b = 1;
	for (; n > 0; n >>= 1, a = mul(a, a)) {
		if (n & 1) {
			b = mul(b, a);
		}
	}
	return b;
}

const int NN = 1e5 + 7;

int f[NN], invf[NN];

int C(int n, int k) {
	return n < k ? 0 : mul(f[n], mul(invf[k], invf[n - k]));
}

int n, k;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0] = invf[0] = 1;
	for (int i = 1; i < NN; ++i) {
		f[i] = mul(f[i - 1], i);
		invf[i] = pw(f[i], M - 2);
	}

	cin >> n >> k >> s;
	
	{
		int cnt1 = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				++cnt1;
			}
		}
		
		if (cnt1 < k || k == 0) {
			cout << 1 << endl;
			return 0;
		}
	}
	
	int ans = 1;
	for (int l = 0; l < n; ++l) {
		int r = l;
		int cnt1 = s[l] - '0';
		while (r + 1 < n && cnt1 + (int)(s[r + 1] - '0') <= k) {
			cnt1 += s[r + 1] - '0';
			++r;
		}
		int cnt0 = r - l + 1 - cnt1;
		if (s[l] == '1') {
			--cnt0;
		} else {
			--cnt1;
		}
		if (cnt0 >= 0 && cnt1 >= 0) {
			ans = add(ans, C(cnt0 + cnt1, cnt0));
		}
	}

	cout << ans << endl;
	return 0;
}