#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int n, x;

const int maxn = 1000010;
int v[maxn];
int a[maxn];
int p[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> x;
	int cmax = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v[a[i]] = max(v[a[i]], cmax);
		cmax = max(cmax, a[i]);
	}
	for (int i = 1; i <= x; i++) {
		v[i] = max(v[i], i);
		p[i] = x+1;
	}
	set<int> cactive;
	for (int i = 1; i <= n; i++) {
		auto it = cactive.upper_bound(a[i]);
		if (it != cactive.end()) {
			p[a[i]] = min(p[a[i]], *it);
		}
		cactive.insert(a[i]);
	}

	ll res = 0LL;
	int minok = 1;

	int cb = x+1;

	for (int i = 1; i <= x; i++) {
		if (i != v[i]) minok = i;
		if (x+1 != p[i]) {
			cb = min(cb, p[i]+1);
		}
	}



	for (int i = 1; i <= x; i++) {
		if (i == cb) break;
		minok = max(minok, v[i-1]);
		minok = max(minok, i);
		res += (x-minok+1LL);

		// cout << i << " : " << x-minok+1LL << endl;
	}
	cout << res << endl;

}