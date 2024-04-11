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
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	std::vector<int> b(n);

	vector <int> val(n);

	map <int, vector <int> > vals;

	for (int i = 0; i < n; i++) {
		cin >> b[i];
		val[i] = b[i] - i;
		vals[val[i]].pb(i);
	}

	ll res = 0;

	for (auto t : vals) {
		ll now = 0;
		for (int x : t.y) {
			now += x + t.x;
		}
		res = max(res, now);
	}

	cout << res << "\n";
}