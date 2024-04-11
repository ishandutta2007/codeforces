#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> freq;
	int cur;
	int h, m;
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		cin >> h >> m;
		cur = 60*h+m;
		if (freq.count(cur) > 0) {
			freq[cur]++;
			ans = max(ans, freq[cur]);
		}
		else freq[cur] = 1;
	}
	cout << ans << endl;
	// cin >> n;
}