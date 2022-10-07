#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> s;
	int N = int(s.length());
	int cur = N;
	deque<int> d;
	d.push_back(cur);
	while (--cur) {
		if (s[cur - 1] == 'r') {
			d.push_front(cur);
		} else {
			d.push_back(cur);
		}
	}
	while (!d.empty()) {
		int c = d.front();
		d.pop_front();
		cout << c << "\n";
	}
	return 0;
}