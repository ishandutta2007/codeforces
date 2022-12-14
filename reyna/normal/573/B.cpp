//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int h[N];
int t[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	memset(t, 63, sizeof t);
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	t[0] = 1;
	for (int i = 1; i < n; ++i) {
		t[i] = min(t[i], min(t[i - 1] + 1, h[i]));
	}
	t[n - 1] = 1;
	for (int i = n - 2; i >= 0; --i)
		t[i] = min(t[i], min(t[i + 1] + 1, h[i]));
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		mx = max(t[i], mx);
	}
	cout << mx << endl;
	return 0;
}