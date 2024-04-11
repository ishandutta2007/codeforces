#include <bits/stdc++.h>

using namespace std;

int n;
const int maxn = 500010;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	string tp;
	int x, y;

	int smallmax = 0, bigmax = 0;
	while (n--) {
		cin >> tp >> x >> y;
		if (x > y) swap(x, y);
		if (tp == "+") {
			// if (x > y) swa
			smallmax = max(smallmax, x);
			bigmax = max(bigmax, y);
		}
		else {
			if (smallmax <= x && bigmax <= y) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	}


	cout.flush();
}