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
	int q;
	cin >> q;
	for (int j = 0; j < q; j++) {
		string s1, s2;
		int n;
		cin >> s1 >> s2;
		n = s1.size();
		vector<int>a(26), b(26);
		for (int i = 0; i < n; i++) {
			a[s1[i] - 'a']++;
		}
		for (int i = 0; i < n; i++) {
			b[s2[i] - 'a']++;
		}
		int c = 0;
		for (int i = 0; i < 26; i++) {
			if (a[i] > 0 && b[i] > 0) {
				cout << "YES" << '\n';
				c = 1;

				break;
			}
		}
		if (c == 0) {
			cout << "NO" << '\n';
		}
	}

	return 0;
}