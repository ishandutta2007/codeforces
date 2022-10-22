#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	vector <int> count(n + 1, 0);
	vector <int> a(n);

	int val = (n - x) / 2;
	int can = n - y + x;

	vector <vector <int> > pos(n + 1);
	vector <int> b(n, -1);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		pos[a[i]].pb(i);
		count[a[i]]++;
	}
	int kek = -1;
	int need = 0;

	for (int i = 0; i <= n; ++i) {
		if (!count[i]) {
			kek = i;
		} else {
			need += max(0, count[i] - val);
		}
	}
	assert(kek != -1);

	//cout << val << " " << can << " " << need << endl;

	if (need > can) {
		cout << "NO\n";
		return;
	}
	int remain = n - y;
	int cur = 0;
	for (int i = 0; i <= n; ++i) {
		while (count[i] > val) {
			if (cur < x) {
				b[pos[i].back()] = a[pos[i].back()];
			} else {
				b[pos[i].back()] = kek;
				--remain;
			}
			--count[i];
			pos[i].pop_back();
			++cur;
		}
	}
	//cout << cur << " " << x << " " << can << endl;
	set <pair <int, int> > counts;
	for (int i = 0; i <= n; ++i) {
		if (count[i]) {
			counts.insert({count[i], i});
		}
	}
	//cout << "SZ: " << n - cur << " " << counts.size() << endl;
	while (cur < x) {
		assert(counts.size());
		auto it = counts.rbegin();
		int des = it->y;
		counts.erase({count[des], des});
		b[pos[des].back()] = a[pos[des].back()];
		--count[des];
		pos[des].pop_back();
		if (count[des]) counts.insert({count[des], des});
		++cur;
	}
	/*cout << cur << " " << n << endl;
	for (auto t : counts) {
		cout << t.x << " ";
	}
	cout << endl;*/
	while (n - cur > 3 && counts.size() > 1) {
		assert(counts.size() >= 2);
		auto it = counts.rbegin();
		int vala = it->y, valb = (++it)->y;
		counts.erase({count[vala], vala});
		counts.erase({count[valb], valb});

		b[pos[vala].back()] = valb;
		b[pos[valb].back()] = vala;
		--count[vala], --count[valb];
		pos[vala].pop_back(), pos[valb].pop_back();
		if (count[vala]) {
			counts.insert({count[vala], vala});
		}
		if (count[valb]) {
			counts.insert({count[valb], valb});
		}
		cur += 2;
	}

	if (counts.size() == 1) {
		if (remain < n - cur) {
			cout << "NO\n";
			return;
		}
		int des = counts.begin()->y;
		for (auto t : pos[des]) {
			b[t] = kek;
			--remain;
			++cur;
		}
		pos[des].clear();
	}

	if ((n - cur) % 2) {
		if (counts.size() != 3) {
			if (!remain) {
				cout << "NO\n";
				return;
			}
			auto it = counts.rbegin();
			int des = it->y;
			counts.erase({count[des], des});

			b[pos[des].back()] = kek;
			--remain;

			--count[des];
			pos[des].pop_back();
			if (count[des]) counts.insert({count[des], des});
			++cur;
		} else {
			assert(counts.size() == 3);
			auto it = counts.rbegin();
			int vala = it->y;
			int valb = (++it)->y;
			int valc = (++it)->y;
			b[pos[vala].back()] = valb;
			b[pos[valb].back()] = valc;
			b[pos[valc].back()] = vala;
			cur += 3;
		}
	}
	if (n - cur == 2) {
		if (counts.size() == 2) {
			auto it = counts.rbegin();
			int vala = it->y;
			int valb = (++it)->y;

			b[pos[vala].back()] = valb;
			b[pos[valb].back()] = vala;
			cur += 2;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (b[i] != kek && b[i] != a[i] && remain) {
			b[i] = kek;
			--remain;
		}
	}
	cout << "YES\n";
	for (int x : b) {
		cout << x + 1 << " ";
	}
	cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}