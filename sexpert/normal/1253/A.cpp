#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool bad, seen;
int gd;

void solve() {
	int n, cnt = 0;
	cin >> n;
	bad = seen = false;
	vector<int> a(n), b(n), d(n);
	for(auto &x : a)
		cin >> x;
	for(auto &x : b)
		cin >> x;
	cnt = 0;
	for(int i = 0; i < n; i++) {
		d[i] = b[i] - a[i];
		if(d[i] < 0)
			bad = true;
		if(d[i] > 0) {
			if(!seen) {
				gd = d[i];
				cnt = 1;
				seen = true;
			}
			else {
				if(d[i] != gd)
					bad = true;
				else
					cnt++;
			}
		}
	}
	int pl = 0, pr = n - 1;
	if(bad) {
		cout << "NO\n";
		return;
	}
	if(cnt == 0) {
		cout << "YES\n";
		return;
	}
	while(d[pl] == 0)
		pl++;
	while(d[pr] == 0)
		pr--;
	if(pr - pl + 1 != cnt) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}