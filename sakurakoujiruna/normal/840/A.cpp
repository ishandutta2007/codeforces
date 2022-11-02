#include <bits/stdc++.h>
using namespace std;

const int N = 2e5L + 11;
using pii = pair <int, int>;

int a[N];
pii b[N];

int ans[N];

int main() {
	ios :: sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	for(int i = 0; i < n; i ++) {
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(b, b + n);
	for(int i = 0; i < n; i ++)
		ans[b[i].second] = a[i];
	for(int i = 0; i < n; i ++)
		cout << ans[i] << ' ';
	cout << '\n';
}