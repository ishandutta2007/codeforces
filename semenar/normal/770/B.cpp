#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string n;
	cin >> n;
	long long x = 0;
	vector<long long> candidates(n.size() + 1);
	x = n[0] - '0';
	candidates[0] = n[0] - '1';
	for (int i = 1; i < candidates.size(); i++) candidates[i] = n[0] - '0';
	for (int i = 1; i < n.size(); i++) {
		for (int j = 0; j < candidates.size(); j++) {
			if (j == i) candidates[j] = candidates[j] * 10 + 8;
			else candidates[j] = candidates[j] * 10 + 9;
		}
		x = x * 10 + (n[i] - '0');
	}
	long long ans = candidates[0];
	for (int i = 1; i < candidates.size(); i++) {
		if (candidates[i] > ans && candidates[i] <= x) ans = candidates[i];
	}
	cout << ans << endl;
	return 0;
}