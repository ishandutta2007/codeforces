#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, k;
int a[N], o[N], ans[N];
pair<int, int> shit[N];

int main() {
	cin >> n >> k;

	for(int i = 1; i < n; i++) cout << "and " << i << " " << i + 1 << endl, cout.flush(), cin >> a[i];
	cout << "and " << 1 << " " << n - ((n & 1) == 0) << endl, cout.flush(), cin >> a[n];
	
	for(int i = 1; i < n; i++) cout << "or " << i << " " << i + 1 << endl, cout.flush(), cin >> o[i];

	for(int t = 1; t <= 30; t++) {
		int pos = 0;
		for(int i = 1; i < n && !pos; i++) {
			int ai = a[i] >> (t - 1) & 1, oi = o[i] >> (t - 1) & 1;
			if(ai == oi) ans[i] |= ai << (t - 1), ans[i + 1] |= ai << (t - 1), pos = i;
		}
		if(pos) {
			for(int i = pos - 1; i >= 1; i--) {
				int lst = ans[i + 1] >> (t - 1) & 1, now;
				int ai = a[i] >> (t - 1) & 1, oi = o[i] >> (t - 1) & 1;
				if(ai == oi) now = lst;
				else now = !lst;
				ans[i] |= now << (t - 1);
			}
			for(int i = pos + 1; i < n; i++) {
				int lst = ans[i] >> (t - 1) & 1, now;
				int ai = a[i] >> (t - 1) & 1, oi = o[i] >> (t - 1) & 1;
				if(ai == oi) now = lst;
				else now = !lst;
				ans[i + 1] |= now << (t - 1);
			}
		}
		else {
			int odd = a[n] >> (t - 1) & 1;
			for(int i = 1; i <= n; i++) ans[i] |= ((i & 1)? odd : !odd) << (t - 1);
		}
	}
	sort(ans + 1, ans + 1 + n);
	cout << "finish " << ans[k] << endl;
	return 0;
}