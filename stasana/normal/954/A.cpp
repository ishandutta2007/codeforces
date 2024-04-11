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

int main() {
	start();
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = "0" + s;
	int res = n;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'R' && s[i - 1] == 'U') {
			s[i] = ' ';
			--res;
		}
		if (s[i] == 'U' && s[i - 1] == 'R') {
			s[i] = ' ';
			--res;
		}
	}
	cout << res;
	return 0;
}