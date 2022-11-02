#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, m, a[509], s[509], b[509], sb[509];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], s[i + 1] = s[i] + a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i], sb[i + 1] = sb[i] + b[i];
	if (s[n] != sb[m]) cout << "NO" << endl;
	else {
		vector<int> p;
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				if (s[j] == sb[i]) p.push_back(j);
			}
		}
		if (p.size() != m + 1) cout << "NO" << endl;
		else {
			bool flag = true;
			for (int i = 0; i < m; i++) {
				bool f = false;
				for (int j = p[i] + 1; j < p[i + 1]; j++) {
					if (a[j] != a[j - 1]) f = true;
				}
				if (p[i] + 1 == p[i + 1]) f = true;
				if (!f) flag = false;
			}
			if (!flag) cout << "NO" << endl;
			else {
				cout << "YES" << endl;
				for (int i = m - 1; i >= 0; i--) {
					vector<int> v(a + p[i], a + p[i + 1]);
					for (int j = 0; j < p[i + 1] - p[i] - 1; j++) {
						int z = *max_element(v.begin(), v.end());
						for (int k = 0; k < v.size(); k++) {
							if (k >= 1 && v[k] == z && v[k - 1] != z) {
								cout << p[i] + k + 1 << " L" << endl;
								v[k] += v[k - 1];
								v.erase(v.begin() + k - 1);
								break;
							}
							if (k + 1 < v.size() && v[k] == z && v[k + 1] != z) {
								cout << p[i] + k + 1 << " R" << endl;
								v[k] += v[k + 1];
								v.erase(v.begin() + k + 1);
								break;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}