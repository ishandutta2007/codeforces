#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int n;
vector<long long> a;
vector<long long> pref_xors;


void count_pref_xors() {
	pref_xors.resize(n + 1);
	pref_xors[0] = 0;
	for (int i = 1; i <= n; ++i) {
		pref_xors[i] = (pref_xors[i - 1] ^ a[i - 1]);
	}
}


int get_res(int tl, int tr) {
	int res = n + 5;
	for (int l1 = tl; l1 < tr; ++l1) {
		for (int l2 = l1 + 1; l2 < tr; ++l2) {
			for (int r2 = l2 + 1; r2 <= tr; ++r2) {
				if ((pref_xors[l1] ^ pref_xors[l2]) > (pref_xors[l2] ^ pref_xors[r2])) {
					res = min(res, (l2 - l1 - 1) + (r2 - l2 - 1));
				}
			}
		}
	}
	return res;
}


int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	count_pref_xors();
	int res = 1e9;
	int mn = n;
	for (int b = 35; b >= 0; --b) {
		int zc = 0;
		int oc = 0;
		for (int i = 0; i < mn; ++i) {
			if ((a[i] >> b) % 2 == 1) {
				++oc;
			}
			else {
				++zc;
			}
		}
		if (oc >= 3) {
			res = 1;
			break;
		}
		mn -= oc;
	}
	if (n - mn <= 100) {
		res = min(res, get_res(mn, n));
	}
	if (res < n) {
		cout << res << "\n";
	}
	else {
		cout << -1 << "\n";
	}
	return 0;
}