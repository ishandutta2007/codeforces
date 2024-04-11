#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef int_fast64_t ll;

void start() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

bool check(string& s, int n) {
	for (int i = 0; i < n; ++i) {
		if (s[i] != s[i + n]) {
			return false;
		}
	}
	return true;
}

int main() {
	start();
	int n;
	cin >> n;
	string s;
	cin >> s;
	int res = n;
	for (int i = 1; i < n; ++i) {
		if (check(s, i)) {
			res = min(res, i + 1 + (n - i * 2));
		}
	}
	cout << res;
	return 0;
}