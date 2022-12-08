#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n;
	cin >> n;
	ll nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	ll p[n+1];
	p[0] = 0LL;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i-1] + nums[i-1];
	}
	ll ans = -p[n];
	int i1 = 0, i2 = 0, i3 = 0;
	ll best[n+1];
	int bindex[n+1];
	for (int i = 0; i <= n; i++) {
		best[i] = -2*p[i];
		bindex[i] = 0;
		for (int j = 0; j <= i; j++) {
			if (2*p[j] - 2*p[i] > best[i]) {
				best[i] = 2*p[j] - 2*p[i];
				bindex[i] = j;
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (2*p[i] + best[j] - p[n] > ans) {
				ans = 2*p[i] + best[j] - p[n];
				i1 = bindex[j];
				i2 = j;
				i3 = i;
			}
		}
	}
	cout << i1 << " " << i2 << " " << i3 << endl;
	cin >> ans;
}