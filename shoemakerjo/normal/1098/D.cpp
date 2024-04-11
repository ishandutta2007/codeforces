#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
using ll = long long;

int q; 
//try up to 31
int pw[32];
ll sums[32];
multiset<int> vals[32];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	pw[0] = 1LL;
	for (int i = 1; i <= 31; i++) {
		pw[i] = pw[i-1]*2;
	}

	cin >> q;
	string tp;
	int x;
	int ct = 0;
	while (q--) {
		cin >> tp >> x;
		int sp = 0;
		for (int i = 0; i < 30; i++) {
			if (pw[i] <= x && x < pw[i+1]) {
				sp = i;
				break;
			}
		}

		if (tp == "+") {
			ct++;
			sums[sp] += x;
			vals[sp].insert(x);
		}
		else { //it is "-"
			ct--;
			sums[sp] -= x;
			vals[sp].erase(vals[sp].find(x));
		}
		ll csum = 0;
		int cans = ct;
		// if (ct) cans--;
		for (int i = 0; i <= 30; i++) {
			if (vals[i].size() == 0) continue;
			if (*vals[i].begin() > 2LL*csum) {
				cans--;
			}
			csum += sums[i];
		}

		cout << cans << '\n';
	}

	cout.flush();
}