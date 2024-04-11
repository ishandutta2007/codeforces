#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define forab(i, a, b) for (int i = a; i < int(b); ++i)
#define fordab(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())
#define pb push_back

typedef long long int64;

int a[100100], n;
vector<int> bad;

bool nowOk() {
	forn (k, n - 1) {
		if (a[k] > a[k + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
	}
	forn (i, n) {
		bool ok = true;
		if (i && a[i - 1] > a[i]) {
			ok = false;
		}
		if (i < n - 1 && a[i] > a[i + 1]) {
			ok = false;
		}
		if (!ok) {
			bad.pb(i);
			if (bad.size() > 6) {
				cout << "NO";
				return 0;
			}
		}
	}
	if (nowOk()) {
		cout << "YES";
		return 0;
	}
	int sz = bad.size();
	forn (i, sz) {
		int j;
		for (j = bad[i]; j < n && a[j] == a[bad[i]]; ++j);
		--j;
		if (j != bad[i]) {
			bad.pb(j);
		}
		for (j = bad[i]; j >= 0 && a[j] == a[bad[i]]; --j);
		++j;
		if (j != bad[i]) {
			bad.pb(j);
		}
	}
	forv (i, bad) {
		forn (j, i) {
			swap(a[bad[i]], a[bad[j]]);
			if (nowOk()) {
				cout << "YES";
				return 0;
			}
			swap(a[bad[i]], a[bad[j]]);
		}
	}
	cout << "NO";
}