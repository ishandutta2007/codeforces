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
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();
	set <int> lt, rt;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			lt.insert(i);
		} else {
			rt.insert(i);
		}
	}
	vector <vector <int> > ops;
	while (true) {
		vector <int> now;
		int l = -1, r = n;
		while (true) {
			if (lt.upper_bound(l) == lt.end()) {
				break;
			}
			int x = *lt.upper_bound(l);
			auto it = rt.lower_bound(r);
			if (it == rt.begin()) break;
			--it;
			int y = *it;
			if (y < x) break;
			now.push_back(x);
			now.push_back(y);
			l = x, r = y;
		}
		if (!now.size()) break;
		for (int i = 0; i < (int) now.size(); i++) {
			if (i % 2 == 0) {
				lt.erase(now[i]);
			} else {
				rt.erase(now[i]);
			}
		}
		sort(now.begin(), now.end());
		ops.pb(now);
	}
	cout << ops.size() << "\n";
	for (auto t : ops) {
		cout << t.size() << "\n";
		for (int x : t) {
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
}