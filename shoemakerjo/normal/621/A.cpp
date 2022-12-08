#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n;
	cin >> n;
	long long ans = 0;
	long long cur;
	vector<long long> odds;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (cur % 2 == 0) ans+=cur;
		else odds.push_back(cur);
	}
	sort (odds.begin(), odds.end());

	for (int i = odds.size()-1; i >= 0; i-=2) {
		if (i > 0) {
			ans += odds[i]+odds[i-1];
		}
	}
	cout << ans << endl;
	// cin >> n;
}