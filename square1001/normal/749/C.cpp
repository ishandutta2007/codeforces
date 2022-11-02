#include <set>
#include <string>
#include <iostream>
using namespace std;
int n; string s;
int main() {
	cin >> n >> s;
	set<int> d, r;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'D') d.insert(i);
		else r.insert(i);
	}
	while (d.size() && r.size()) {
		if (*d.begin() < *r.begin()) {
			r.erase(r.begin());
			d.insert(*d.begin() + n);
			d.erase(d.begin());
		}
		else {
			d.erase(d.begin());
			r.insert(*r.begin() + n);
			r.erase(r.begin());
		}
	}
	if (d.size()) cout << "D" << endl;
	else cout << "R" << endl;
	return 0;
}