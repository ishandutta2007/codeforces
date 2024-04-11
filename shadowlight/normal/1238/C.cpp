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
	int h, n;
	cin >> h >> n;
	vector <int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	p.push_back(0);
	int res = 0;
	int now = 0;
	while (now < n - 1) {
		if (p[now + 1] == p[now + 2] + 1) {
			now += 2;
		} else {
			res++;
			now++;
		}
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		solve();
	}
}