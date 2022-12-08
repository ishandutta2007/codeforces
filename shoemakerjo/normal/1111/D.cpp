#include <bits/stdc++.h>

using namespace std;

int n;
const int maxn = 100010;
const int mod = 1000000007;

int dp[maxn];
int nums[maxn];

int cdp[maxn];
int ans[55][55];
int ct[55];
int facts[maxn];
int ifacts[maxn];

int q;

string s;


int modpow(int a, int b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		int tmp = modpow(a, b/2);
		return tmp*1LL*tmp%mod;
	}
	int tmp = modpow(a, b-1);
	return tmp *1LL*a %mod;
}

int inv(int u) {
	return modpow(u, mod-2);
}

void add(int & a, int b) {
	a = (a + b)%mod;
}
void sub(int &a, int b) {
	a = (a + mod - b)%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> q;
	n = s.length();
	for (int i = 1; i <= n; i++) {
		nums[i] = s[i-1] - 'a';
		if (nums[i] < 0 || nums[i] >= 26) {
			nums[i] = s[i-1] - 'A' + 26;
		}
		ct[nums[i]]++;
	}
	dp[0] = 1;

	facts[0] = 1;
	for (int i = 1; i <= n; i++) {
		facts[i] = facts[i-1]*1LL * i % mod;
		ifacts[i] = inv(facts[i]);

		// cout << i <<  " :: " << facts[i] * 1LL * ifacts[i] % mod << "   " << 
		// 	facts[i] << endl;
	}

	int cont = facts[n/2]*1LL*facts[n/2]%mod;
	// cout << "pre cont: " << cont << endl;

	for (int i = 0; i < 52; i++) {
		if (ct[i] == 0) continue;
		for (int j = n/2; j >= ct[i]; j--) {
			add(dp[j], dp[j-ct[i]]);
		}
		// cout << i << " : " << ct[i] << endl;
		cont = cont * 1LL * ifacts[ct[i]] % mod;
	}

	// cout << "cont: " << cont << endl;

	// for (int j = 0; j <= n/2; j++) {
	// 	cout << j << " :: " << dp[j] << endl;
	// }
	
	for (int i = 0; i < 52; i++) {
		for (int j = i; j < 52; j++) {
			if (ct[i] == 0 || ct[j] == 0) continue;

			for (int k = 0; k <= n/2; k++) {
				cdp[k] = dp[k];
			}
			for (int k = ct[i]; k <= n/2; k++) {
				sub(cdp[k], cdp[k-ct[i]]);
			}
			if (i != j) {
				for (int k = ct[j]; k <= n/2; k++) {
					sub(cdp[k], cdp[k-ct[j]]);
				}
			}
			// if (i == j) cout << "thing: " << cdp[n/2] << endl;
			ans[i][j] = ans[j][i] = cdp[n/2]*2LL %mod;
		}
	}
	int u, v;
	while (q--) {
		cin >> u >> v;
		u = nums[u];
		v = nums[v];
		cout << ans[u][v]*1LL*cont%mod << '\n';
	}
	cout.flush();

}