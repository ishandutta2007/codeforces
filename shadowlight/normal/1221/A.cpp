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
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> cnt(30, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int now = 0;
		while (x % 2 == 0) {
			x /= 2;
			now++;
		}
		cnt[now]++;
	}
	for (int i = 0; i <= 10; i++) {
		cnt[i + 1] += cnt[i] / 2;
	}
	if (cnt[11]) {
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
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		solve();
	}
}