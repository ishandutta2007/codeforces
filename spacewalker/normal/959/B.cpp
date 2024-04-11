#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#define INF 1000000000000000000

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, m; cin >> n >> k >> m;
	vector<string> words(n, "");
	unordered_map<string, int> placeInList;
	vector<ll> costs(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> words[i];
		placeInList[words[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> costs[i];
	}
	for (int grp = 0; grp < k; ++grp) {
		int x; cin >> x;
		vector<int> members(x, 0);
		for (int i = 0; i < x; ++i) {
			cin >> members[i];
			--members[i];
		}
		ll lowestCost = INF;
		for (int i = 0; i < x; ++i) {
			lowestCost = min(lowestCost, costs[members[i]]);
		}
		for (int i = 0; i < x; ++i) {
			costs[members[i]] = lowestCost;
		}
	}
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		string word; cin >> word;
		ans += costs[placeInList[word]];
	}
	cout << ans << endl;
	return 0;
}