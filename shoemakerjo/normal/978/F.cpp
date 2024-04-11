#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int skill[n+1];
	vector<pii> vp;
	for (int i = 1; i <= n; i++) {
		cin >> skill[i];
		vp.push_back(make_pair(skill[i], i));
	}
	sort(vp.begin(), vp.end());
	int sub[n+1];
	fill(sub, sub+n+1, 0);
	int a, b;
	while (k--) {
		cin >> a >> b;
		if (skill[a] > skill[b]) sub[a]++;
		else if (skill[b] > skill[a]) sub[b]++;
	}
	int leq[n+1];
	int prev = -1;
	int ans[n+1];
	for (int i = 0; i < n; i++) {
		int sc = vp[i].first;
		int ind = vp[i].second;
		if (sc == prev) {
			leq[i] = leq[i-1];
		}
		else {
			prev = sc;
			leq[i] = i;
		}
		// cout << ind << ": " << leq[i] << endl;
		ans[ind] = leq[i] - sub[ind];
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cin >> n;
}