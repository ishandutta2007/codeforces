#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v;
	int n;
	cin >> n;
	bool ans = false;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		v.push_back(cur);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size()-2; i++) {
		if (v[i] + v[i+1] > v[i+2]) ans = true;
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> n;
}