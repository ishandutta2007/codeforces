#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
#define int long long
signed main() {
	string a;
	cin >> a;
	int n = a.size();
	vector<vector<int>>ans;
	while (1) {
		int r = n - 1;
		vector<int>cnt;
		vector<int>c(2000);
		for (int i = 0; i < n; i++) {
			if (a[i] == '(') {
				for (int j = r; j > i; j--) {
					if (a[j] == ')') {
						cnt.push_back(i);
						cnt.push_back(j);
						c[i] = 1;
						c[j] = 1;
						r = j - 1;
						break;
					}
				}
			}
		}
		if (cnt.size() == 0) {
			break;
		}
		string s2;
		for (int i = 0; i < n; i++) {
			if (c[i] == 0) {
				s2.push_back(a[i]);
			}
		}
		n = s2.size();
		a = s2;
		sort(cnt.begin(), cnt.end());
		ans.push_back(cnt);
		
	}
	cout << ans.size() << '\n'; 
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].size() << '\n';
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] + 1 << " ";
		}
		cout << '\n';
	}

	return 0;
}