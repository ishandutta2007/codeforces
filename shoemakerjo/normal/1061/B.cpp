#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define maxn 100010
ll a[maxn];
int n, m;
vector<int> keep;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	int maxind = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > a[maxind]) maxind = i;
	}
	ll ans = 0LL;
	for (int i = 0; i < n; i++) {
		if (i == maxind) continue;
		if (a[i] <= 0) continue;
		ans += a[i]-1;
		keep.push_back(a[i]);
	}

	sort(keep.begin(), keep.end());
	reverse(keep.begin(), keep.end());
	for (int i = 1; i < keep.size(); i++) {
		if (keep[i] >= keep[i-1]) {
			keep[i] = keep[i-1]-1;
		}
	}
	while (keep[keep.size()-1] <= 0) {
		keep.pop_back();
	}
	ans += min((ll) keep.size(), a[maxind]-1LL);

	cout << ans << endl;
}