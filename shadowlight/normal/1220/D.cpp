#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int LOGN = 100;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <ll> b(n);
	vector <vector <ll> > c(LOGN);
	vector <ll> odd, even;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		ll y = x;
		ll cnt = 0;
		while (x % 2 == 0) {
			x /= 2;
			cnt++;
		}
		c[cnt].push_back(y);
	}
	int maxs = 0, pi = -1;
	for (int i = 0; i < LOGN; i++) {
		if (c[i].size() > maxs) {
			maxs = c[i].size();
			pi = i;
		}
	}
	cout << n - maxs << "\n";
	for (int i = 0; i < LOGN; i++) {
		if (i == pi) continue;
		for (ll x : c[i]) {
			cout << x << " ";
		}
	}
	cout << "\n";
}