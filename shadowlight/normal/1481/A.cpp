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
	int x, y;
	cin >> x >> y;

	vector <int> cnt(4, 0);
	string tet = "UDRL";

	string s;
	cin >> s;
	for (char c : s) {
		for (int i = 0; i < 4; ++i) {
			if (tet[i] == c) {
				++cnt[i];
			}
		}
	}
	if (y < 0) {
		swap(cnt[0], cnt[1]);
		y = -y;
	}
	if (x < 0) {
		swap(cnt[2], cnt[3]);
		x = -x;
	}
	cout << (cnt[0] >= y && cnt[2] >= x ? "YES\n" : "NO\n");
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}