#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> nums;
	int cur;
	int ct[100010];
	fill(ct, ct+100010, 0);
	for (int i = 0; i < n; i++) {
		cin >> cur;
		ct[cur]++;
	}
	bool awin = false;
	for (int i = 0; i <= 100000; i++) {
		if (ct[i]%2 == 1) {
			awin = true;
		}
	}
	if (awin) cout << "Conan" << endl;
	else cout << "Agasa" << endl;
	cin >> n;

}