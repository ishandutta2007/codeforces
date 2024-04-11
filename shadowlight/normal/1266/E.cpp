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
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	vector <int> cnt_in(n, 0);
	int sum_in = 0;
	map <pair <int, int>, int> qq;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int s, t, u;
		cin >> s >> t >> u;
		if (qq.count(mp(s, t))) {
			int u = qq[mp(s, t)];
			cnt_in[u]--;
			if (cnt_in[u] < a[u]) {
				sum_in--;
			}
			qq.erase({s, t});
		}
		if (u) {
			u--;
			qq[mp(s, t)] = u;
			cnt_in[u]++;
			if (cnt_in[u] <= a[u]) {
				sum_in++;
			}
		}
		cout << sum - sum_in << "\n";
	}

}