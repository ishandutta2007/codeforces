#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int calculate(const string& s1, const string& s2) {
	string s = s1 + "$" + s2;
	int n = (int) s.size();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (pi[i] == s1.size()) {
			++res;
		}
	}
	return res;
}

struct Rule {
	string word;
	int left, right;

	void Read() {
		cin >> word >> left >> right;
	}
};

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	int n;
	cin >> n;
	vector < Rule > rules(n);
	for (int i = 0; i < n; ++i) {
		rules[i].Read();
	}

	int res = 0;
	set < string > good;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = i; j < s.size(); ++j) {
			string current = s.substr(i, j - i + 1);
			bool nice = true;
			bool need_break = false;
			for (int k = 0; k < n; ++k) {
				int cnt = calculate(current, rules[k].word);
				if (cnt < rules[k].left) {
					need_break = true;
					break;
				}
				if (cnt > rules[k].right) {
					nice = false;
					break;
				}
			}

			if (need_break) {
				break;
			}
			if (nice) {
				good.insert(current);
			}
		}
	}

	cout << good.size() << endl;


	return 0;
}