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

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "First" << endl;
		for (int i = 0; i < n; ++i) {
			cout << i + 1 << " ";
		}
		for (int i = 0; i < n; ++i) {
			cout << i + 1 << " ";
		}
		cout << "\n";
		return 0;
	}
	cout << "Second" << endl;
	vector <int> a(n), b(n);
	for (int i = 0; i < 2 * n; ++i) {
		int x;
		cin >> x;
		--x;
		if (!a[x]) {
			a[x] = i + 1;
		} else {
			b[x] = i + 1;
		}
	}
	vector <vector <pair <int, int> > > gr(n);
	for (int i = 0; i < n; ++i) {
		gr[a[i] % n].pb({b[i] % n, i});
		gr[b[i] % n].pb({a[i] % n, i});
	}
	vector <bool> used(n, false);
	vector <int> res(n, 0);
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		int now = gr[i][0].x;
		used[i] = true;
		res[gr[i][0].y] = (i == a[gr[i][0].y] % n ? a[gr[i][0].y] : b[gr[i][0].y]);
		if (now == i) {
			res[gr[i][0].y] = a[gr[i][0].y];
			continue;
		}
		int pr = i;
		while (!used[now]) {
			used[now] = true;
			bool was = false;
			for (auto e : gr[now]) {
				if (e.x == pr && !was) {
					was = true;
					continue;
				}
				res[e.y] = (now == a[e.y] % n ? a[e.y] : b[e.y]);
				pr = now;
				now = e.x;
				break;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += res[i];
		sum %= 2 * n;
	}
	if (sum) {
		for (int i = 0; i < n; ++i) {
			res[i] = a[i] + b[i] - res[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
}