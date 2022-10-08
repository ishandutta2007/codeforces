#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

int ff(vector<int> a) {
	int n = (int) a.size();
	if (n == 1) return n;
	bool F = true;
	for (int i = 1; i < n; i ++)
		if (a[i-1] > a[i]) F = false;
	if (F) return n;
	vector<int> b, c;
	for (int i = 0; i < n/2; i ++) b.pb(a[i]);
	for (int i = 0; i < n/2; i ++) c.pb(a[i+n/2]);
	return max(ff(b), ff(c));
}

int main() {
	int n;
	vector<int> a;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		int x; cin >> x;
		a.pb(x);
	}
	cout << ff(a) << endl;
	return 0;
}