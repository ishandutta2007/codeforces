#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool IsSubStr(string a, string b) {
	int n = a.size();
	int m = b.size();
	bool ans = false;
	for (int i = 0; i <= m - n; ++i) {
		bool tmp = true;
		for (int j = i; j < i + n; ++j) {
			if (a[j - i] != b[j])
				tmp = false;
		}
		if (tmp) {
			ans = true;
			break;
		}
	}
	return ans;
}

bool cmp(string a, string b) {
	if (IsSubStr(a, b))
		return true;
	else
		return false;
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (auto& i : a)
		cin >> i;
	bool tmp = true;
	int last = n;
	while (tmp) {
		tmp = false;
		for (int i = 0; i < last - 1; ++i) {
			if (!IsSubStr(a[i], a[i+1])) {
				swap(a[i], a[i + 1]);
				tmp = true;
			}
		}
		last--;
	}
	bool check = true;
	for (int i = 0; i < n - 1; ++i) {
		if (!IsSubStr(a[i], a[i + 1])) {
			check = false;
			break;
		}
	}
	if (check) {
		cout << "YES\n";
		for (auto i : a)
			cout << i << "\n";
	}
	else
		cout << "NO";
}