#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector <map <int, bool>> a(n);

	vector <int> c(n);

	set <int> b;
	set <int> bb;
	set <int> q;

	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		if (c[i] == 1) {
			b.insert(i);
			bb.insert(i);
		} else if (c[i]) {
			q.insert(i);
		}
	}

	vector <int> used(n, 0);

	int now = n - 1;

	for (int i = 0; i < n; ++i) {
		if (!c[i]) {
			continue;
		}

		if (c[i] == 1) {
			if (used[i] != 2) a[now--][i] = true;
			continue;
		}

		a[now][i] = 1;
		if (c[i] == 3) {
			auto it = q.upper_bound(i);
			if (it == q.end()) {
				auto it1 = b.upper_bound(i);
				if (it1 == b.end()) {
					cout << "-1\n";
					return 0;
				}
				int nxt = *it1;
				a[now][nxt] = 1;
				++used[nxt];
				bb.erase(*it1);
				if (used[nxt] == 2) {
					b.erase(it1);
				}
				--now;
			} else {
				int nxt = *it; 
				a[now][nxt] = 1;
				--now;
				q.erase(it);
			}
		} else {
			auto it = bb.upper_bound(i);
			if (it == bb.end()) {
				cout << "-1\n";
				return 0;
			}
			a[now][*it] = 1;
			--now;
			used[*it] = 2;
			b.erase(*it);
			bb.erase(*it);
		}
	}

	int res = 0;

	for (int i = 0; i < n; ++i) {
		res += a[i].size();
	}

	cout << res << "\n";

	for (int i = 0; i < n; ++i) {
		for (auto [x, y] : a[i]) {
			cout << n - i << " " << x + 1 << "\n";
		}
	}


}