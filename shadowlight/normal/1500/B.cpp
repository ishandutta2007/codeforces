#include <bits/stdc++.h>
#define ll long long
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	ll k;
	cin >> n >> m >> k;

	map <int, int> posx, posy;

	vector <int> a(n), b(m);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		posx[a[i]] = i;
	}
	for (int j = 0; j < m; ++j) {
		cin >> b[j];
		posy[b[j]] = j;
	}

	if (n > m) {
		swap(n, m);
		swap(a, b);
		swap(posx, posy);
	}

	vector <int> res(2 * m, 0);

	for (int i = 0; i < n; ++i) {
		int x = a[i];
		if (posy.count(x)) {
			int j = posy[x];
			res[j + m - i] += 1;
			//cout << i << " " << j << " " << j + m - i << endl;
		}
	}
	vector <int> shift(m, 0);
	for (int i = 0; i < m; ++i) {
		shift[i] = n - (res[i] + res[i + m]);
		//cout << i << " " << shift[i] << endl;
	}
	ll total = 0;
	ll len = 0;
	vector <int> path;
	vector <int> cycle;
	map <int, int> was;

	int now = 0;
	while (!was[now]) {
		was[now] = true;
		path.pb(now);
		if (total + shift[now] >= k) {
			ll need = k - total;
			for (int i = 0; i < n; ++i) {
				int j = (i + now) % m;
				len += 1;
				if (a[i] != b[j]) {
					--need;
					if (!need) {
						cout << len << "\n";
						return 0;
					}
				}
			}
		}
		total += shift[now];
		len += n;
		now = (now + n) % m;
	}
	int len_cycle = 0;
	int plus_cycle = 0;
	while (path.back() != now) {
		len_cycle += n;
		plus_cycle += shift[path.back()];
		cycle.pb(path.back());
		path.pop_back();
	}
	len_cycle += n;
	plus_cycle += shift[now];
	cycle.pb(now);
	reverse(all(cycle));


	ll need = k - total;
	assert(plus_cycle);

	ll full = (need - 1) / plus_cycle;
	
	len += full * len_cycle;
	total += full * plus_cycle;
	if (total == k) {
		cout << len << "\n";
		return 0;
	}

	for (int x : cycle) {
		if (total + shift[now] >= k) {
			ll need = k - total;
			for (int i = 0; i < n; ++i) {
				int j = (i + now) % m;
				len += 1;
				if (a[i] != b[j]) {
					--need;
					if (!need) {
						cout << len << "\n";
						return 0;
					}
				}
			}
		}
		total += shift[now];
		len += n;
		now = (now + n) % m;
	}
	assert(false);
}