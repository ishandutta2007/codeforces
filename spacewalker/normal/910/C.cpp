#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1000000000000000

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> weight(26, 0);
	vector<bool> canZero(26, true);
	for (int i = 0; i < n; ++i) {
		string word; cin >> word;
		canZero[word[0] - 'a'] = false;
		reverse(word.begin(), word.end());
		int p10 = 1;
		for (int j = 0; j < word.size(); ++j, p10 *= 10) {
			weight[word[j] - 'a'] += p10;
		}
	}
	vector<bool> isAssigned(26, false);
	ll ans = 0;
	for (ll valta = 0; valta <= 26; ++valta) {
		ll maxVal = -INF;
		ll maxIdx = -1;
		for (int i = 0; i < 26; ++i) {
			if ((((valta == 0) && (canZero[i])) || (valta != 0)) &&
				!isAssigned[i] && weight[i] > maxVal && weight[i] > 0) {
				maxVal = weight[i];
				maxIdx = i;
			}
		}
		if (maxIdx >= 0) {
			ans += (valta * maxVal);
			isAssigned[maxIdx] = true;
		}
	}
	cout << ans << endl;
	return 0;
}