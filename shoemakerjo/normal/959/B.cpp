#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, m;
	cin >> n >> k >> m;
	ll cost[n+1];
	string words[n+1];
	map<string, int> ind;
	for (int i = 1; i <= n; i++) {
		cin >> words[i];
		ind[words[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	int x;
	ll mins[k];
	int group[n+1];
	int cur;
	for (int i = 0; i < k; i++) {
		cin >> x;
		mins[i] = 2000000000;
		for (int j = 0; j < x; j++) {
			cin >> cur;
			group[cur] = i;
			mins[i] = min(mins[i], cost[cur]);
		}

	}
	string tmp;
	ll ans = 0LL;
	while (m--) {
		cin >> tmp;
		int cind = ind[tmp];
		ans += mins[group[cind]];
	}
	cout << ans << endl;
	cin >> n;

}