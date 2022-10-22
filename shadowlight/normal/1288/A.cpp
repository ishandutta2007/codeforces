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
	int n, d;
	cin >> n >> d;
	int x = sqrt(d);
	for (int sd = -5; sd <= 5; sd++) {
		int xx = sd + x;
		if (xx < 0) continue;
		if (xx + ceil((double)d / (xx + 1)) <= n) {
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