#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	vector < int > cnt(26);
	for (int i = 0; i < s.size(); ++i) {
		++cnt[s[i] - 'a'];
	}

	if (*max_element(cnt.begin(), cnt.end()) > 1 || n == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}