#include <map>
#include <set>
#include <vector>
#include <iostream>
using namespace std;
int n, x;
int main() {
	cin >> n;
	set<int> s;
	map<int, bool> l, r;
	for (int i = 0; i < n; i++) {
		cin >> x; s.insert(x); l[x] = r[x] = true;
		if (i >= 1) {
			set<int>::iterator it = s.lower_bound(x);
			bool flag = false;
			if (it != s.begin()) {
				it--;
				if (r[*it]) {
					cout << *it << ' ';
					r[*it] = false;
					flag = true;
				}
				it++;
			}
			if (!flag) {
				it++;
				cout << *it << ' ';
				l[*it] = false;
			}
		}
	}
	return 0;
}