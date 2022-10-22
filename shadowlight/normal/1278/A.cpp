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
	string p, h;
	cin >> p >> h;
	sort(p.begin(), p.end());
	for (int i = 0; i < h.size(); i++) {
		string t = h.substr(i, p.size());
		sort(t.begin(), t.end());
		if (t == p) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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
	for (int i = 0; i < t; i++) {
		solve();
	}

}