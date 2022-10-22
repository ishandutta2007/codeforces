#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll good = 0;
	vector <pair <int, int> > a;
	vector <int> b;
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		int mink = INF;
		bool now_good = false;
		for (int i = 0; i < l; i++) {
			int x;
			cin >> x;
			if (!i) {
				b.push_back(x);
			}
			if (i == l - 1) {
				a.push_back({x, -1});
			}
			if (mink > x) {
				mink = x;
			} else if (mink < x) {
				if (!now_good) {
					good++;
				}
				now_good = true;
			}
		}
		a.back().second = b.back();
		if (now_good) a.pop_back(), b.pop_back();
	}
	ll res = good * good + (n - good) * good * 2;
	sort(b.begin(), b.end());
	for (auto p : a) {
		int x = p.first, y = p.second;
		int pos = upper_bound(b.begin(), b.end(), x) - b.begin();
		res += (b.size() - pos);
		//cout << x << " " << b.size() - pos << "\n";
	}
	cout << res << "\n";
}