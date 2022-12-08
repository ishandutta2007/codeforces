#include <bits/stdc++.h>

using namespace std;
#define ld long double

int n, k;

ld facts[22];

ld vals[22];

ld lv[22]; //level values


ld psum[1 << 20];

int pc[1 << 20]; //pop counts

ld choose(int a, int b) {
	ld res = facts[a];
	res /= facts[b];
	res /= facts[a-b];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}

	facts[0] = 1.0;
	for (int i = 1; i <= 21; i++) {
		facts[i] = facts[i-1] * i;
	}

	for (int mask = 0; mask < (1 << n); mask++) {
		psum[mask] = 0.0;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) psum[mask] += vals[i];
		}
		pc[mask] = __builtin_popcount(mask);
	}

	cout << fixed << setprecision(10);

	for (int i = 0; i < n; i++) {

		if (abs(vals[i] - 0.0) < .0001) {
			cout << 0.0 << " ";
			continue;
		}

		for (int j = 0; j < 22; j++) {
			lv[j] = 0.0;
		}

		for (int mask = 0; mask < (1 << n); mask++) {
			if (mask & (1 << i)) continue;
			int sz = pc[mask];

			lv[sz] += vals[i]/(vals[i] + psum[mask]);


		}
		for (int j = n-1; j >= 0; j--) {
			for (int k = j+1; k <= n; k++) {
				lv[j] -= choose(k, k-j) * lv[k];
			}
		}

		ld ans = 0.0;
		for (int j = n-k; j <= n; j++) {
			ans += lv[j];
		}

		cout << ans << " ";
	}
	cout << endl;

}