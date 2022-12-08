#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define ll long long
#define pll pair<pair<ll, ll>, int>
int n;
vector<pll> st;
int ans[maxn];
// ll xc[maxn];
// ll yc[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	ll xc,  yc;
	for (int i = 0; i < n; i++) {
		cin >> xc >> yc;
		st.push_back(pll(pair<ll, ll>(xc, yc), i));
	}
	ll cx = 0;
	ll cy = 0;
	srand(time(NULL));
	random_shuffle(st.begin(), st.end());
	for (int i = 0; i < n; i++) {
		xc = st[i].first.first;
		yc = st[i].first.second;
		int ind = st[i].second;
		if (cx == 0 && cy == 0) {
			// cout << 1 << " ";
			ans[ind] = 1;
			cx = xc;
			cy = yc;
			continue;
		}
		ll dot = cx*xc + cy*yc;
		if (dot >= 0) {
			ans[ind] = -1;
			// cout << -1 << " ";
			cx -= xc;
			cy -= yc;
		}
		else {
			ans[ind] = 1;
			// cout << 1 << " ";
			cx += xc;
			cy += yc;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	// cout << sqrt(cx*cx + cy*cy) << endl;

	cout << endl;
	cin >> n;
}