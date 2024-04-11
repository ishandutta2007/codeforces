#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int>a(n);
	vector<int>b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	vector<int>ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				ans.push_back(a[i]);
			}
		}
	}
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}