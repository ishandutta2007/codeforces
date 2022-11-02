#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string s;
		cin >> s;
		bool flag = false;
		string ans = "YES\n";
		for (int j = 0; j < s.size() - 1; ++j) {
			if (s[j] == '1' && s[j+1] == '1')
				flag = true;
			else if (flag && s[j] == '0' && s[j + 1] == '0')
					ans = "NO\n";
		}
		cout << ans;
	}
}