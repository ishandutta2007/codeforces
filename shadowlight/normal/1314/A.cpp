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
	map <int, set <pair <int, int> > > q;
	map <int, ll> sum;
	vector <int> a(n), t(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < n; i++) {
		q[a[i]].insert({t[i], i});
		sum[a[i]] += t[i];
	}
	ll res = 0;
	while (!q.empty()) {
		int val = q.begin()->first;
		auto nowq = move(q.begin()->second);
		q.erase(q.begin());
		if (nowq.size() == 1) {
			continue;
		}

		sum[val] -= nowq.rbegin()->first;
		nowq.erase(*nowq.rbegin());
		res += sum[val];

		while (q[val + 1].size()) {
			nowq.insert(*q[val + 1].begin());
			sum[val] += q[val + 1].begin()->first;
			q[val + 1].erase(q[val + 1].begin());
		}

		sum[val + 1] = sum[val];
		swap(q[val + 1], nowq);
	}

	cout << res << "\n";
}