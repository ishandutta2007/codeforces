#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, v;
	cin >> n >> v;
	vector<int> ans;
	bool ok;
	int amount;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> amount;
		ok = false;
		for (int j = 0; j < amount; j++) {
			cin >> cur;
			if (v > cur) ok = true;
		}
		if (ok) ans.push_back(i+1);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		if (i > 0) cout << " ";
		cout << ans[i];
	}
	if (ans.size() > 0) cout << endl;
	// cin >> n;
}