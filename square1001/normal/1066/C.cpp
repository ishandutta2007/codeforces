#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int q, id, pl[200009]; string s;
int main() {
	cin >> q;
	int vl = 0, vr = 0;
	while (q--) {
		cin >> s >> id;
		if (s == "L") {
			pl[id] = --vl;
		}
		if (s == "R") {
			pl[id] = vr++;
		}
		if (s == "?") {
			cout << min(pl[id] - vl, vr - pl[id] - 1) << '\n';
		}
	}
	return 0;
}