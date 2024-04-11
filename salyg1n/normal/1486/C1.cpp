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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int l = 1, r;
	cin >> r;
	cout << "? " << l << " " << r << endl;
	int pos, last;
	cin >> last;
	while (r - l > 1) {
		int m = (r + l) / 2;
		if (last >= m) {
			cout << "? " << m << " " << r << endl;
			cin >> pos;
			if (pos == last) {
				l = m;
				last = pos;	
			}
			else {
				r = m;
				cout << "? " << l << " " << r << endl;
				cin >> last;
			}
		}
		else {
			cout << "? " << l << " " << m << endl;
			cin >> pos;
			if (pos == last) {
				r = m;
				last = pos;
			}
			else {
				l = m;
				cout << "? " << l << " " << r << endl;
				cin >> last;
			}
		}
	}
	cout << "! " << r + l - last << endl;
}