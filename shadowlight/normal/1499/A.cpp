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
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	int w, b;
	cin >> w >> b;

	if (k1 > k2) swap(k1, k2);
	int wa = k1 + (k2 - k1) / 2;
	k1 = n - k1, k2 = n - k2;
	swap(k1, k2);
	int ba = k1 + (k2 - k1) / 2;
	if (wa >= w && ba >= b) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
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