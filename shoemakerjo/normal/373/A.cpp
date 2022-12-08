#include <bits/stdc++.h>

using namespace std;

int main() {
	int big = 0;
	int k; cin >> k;
	int nums[10];
	for (int i = 0; i < 10; i++) {
		nums[i] = 0;
	}
	string line;
	for (int i = 0; i < 4; i++) {
		cin >> line;
		for (int j = 0; j < 4; j++) {
			if (line[j] == '.') continue;
			nums[line[j]-'0']++;
			big = max(big, nums[line[j]-'0']);
		}
	}
	if (big > 2*k) cout << "NO" << endl;
	else cout << "YES" << endl;
	cin >> big;
}