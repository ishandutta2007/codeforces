#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	string strt;
	cin >> strt;

	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	int ans = 0;
	
	vector<bool> cur(n);
	for (int i = 0; i < n; i++) {
		cur[i] = strt[i] - '0';
		ans += cur[i];
	}

	int tmpans = ans;

	for (int t = 0; t <= 240; t++) {
		for (int i = 0; i < n; i++) {
			if (b[i] == 0) {
				if (cur[i] == 0) tmpans++;
				else tmpans--;
				cur[i] = !cur[i];
				b[i] += a[i];
			}
			b[i]--;
		}
		ans = max(ans, tmpans);
	}

	cout << ans << endl;

	return 0;
}