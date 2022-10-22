#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int LOGN = 30;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector <pair <vector<int>, int>> groups;
	groups.pb({a, 0});

	for (int i = LOGN - 1; i >= 0; --i) {
		vector <pair <vector<int>, int>> ngroups;
		for (auto& t : groups) {
			auto& group = t.x;
			int cnt = t.y;
			vector<int> with0, with1;
			for (int x : group) {
				if ((1 << i) & x) {
					with0.pb(x);
				} else {
					with1.pb(x);
				}
			}
			if (with0.size()) ngroups.pb({with0, cnt + max(0, (int) with1.size() - 1)});
			if (with1.size()) ngroups.pb({with1, cnt + max(0, (int) with0.size() - 1)});
		}
		groups = ngroups;
	}
	int res = n;
	for (auto& t : groups) {
		res = min(res, t.y);
	}
	cout << res << "\n";
}