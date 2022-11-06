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

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(all(a));
	vector<bool> taken(n, true);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] % a[i] == 0) taken[j] = false;

	int ans = 0;
	for (int i = 0; i < n; i++) ans += taken[i];
	cout << ans << endl;

	return 0;
}