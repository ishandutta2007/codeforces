#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

int occ[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (char c : s) {
			++occ[c - 'a'];
		}
		for (int b = 0; b < 26; ++b) {
			if (occ[b] % 2 == 1) arr[i] |= (1 << b);
			occ[b] = 0;
		}
	}
	map<int, int> occCount;
	ll ans = 0;
	for (int i = 0; i < n; ++i) occCount[arr[i]]++;
	for (int i = 0; i < n; ++i) {
		ans += occCount[arr[i]];
		for (int b = 0; b < 26; ++b) {
			ans += occCount[arr[i]^(1<<b)];
		}
	}
	printf("%lld\n", (ans-n)/2);
	return 0;
}