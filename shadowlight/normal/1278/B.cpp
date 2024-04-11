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
	int a, b;
	cin >> a >> b;
	int d = abs(b - a);
	for (int k = 0; ; k++) {
		int value = k * (k + 1) / 2;
		if ((value + d) % 2) continue;
		if (d > value) continue;
		cout << k << "\n";
		return;
	}
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}