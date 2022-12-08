#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	if (k1 == 1 || k2 == 1 || k3 == 1) {
		cout << "YES" << endl;
	}
	else {
		vector<int> vals;
		vals.push_back(k1);
		vals.push_back(k2);
		vals.push_back(k3);
		sort(vals.begin(), vals.end());
		if (vals[0] == 2 && vals[1] == 2) {
			cout << "YES" << endl;
		}
		else {
			if (vals[0] == 3 && vals[1] == 3 && vals[2] == 3) {
				cout << "YES" << endl;
			}
			else {
				if (vals[0] == 2 && vals[1] == 4 && vals[2] == 4) {
					cout << "YES" << endl;
				}
				else {
					cout << "NO" << endl;
				}
			}
		}
	}
	cin >> k1;
}