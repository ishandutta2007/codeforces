// karelia18w-49 m8S9jYTTGG
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <random>
#include <cstring>
#include <cassert>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll p, k;
	cin >> p >> k;
	vector<ll> ans;
	for (int i = 0; p; i++) {
		if (i % 2) {
			ans.push_back((k - p % k) % k);
			p += ans.back();
		}
		else {
			ans.push_back(p % k);
			p -= ans.back();
		}
		p /= k;
	}
	cout << ans.size() << '\n';
	for (ll i : ans)
		cout << i << ' ';
}