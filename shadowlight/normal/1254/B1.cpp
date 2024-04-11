#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MAXN = 1e6 + 7;

vector <int> a;

const ll INF = 1e18 + 7;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	ll sum = 0;

	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	if (sum == 1) {
		cout << "-1\n";
		return 0;
	}

	auto sa = a;

	ll res = INF;
	for (int k = 2; k < MAXN; k++) {
		if (sum % k) continue;
		a = sa;
		ll now = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] < 0) {
				now -= a[i];
				a[i + 1] += a[i];
			} else {
				ll d = a[i] % k;
				if (d < k - d) {
					now += d;
					a[i + 1] += d;
				} else {
					now += k - d;
					a[i + 1] -= k - d;
				}
			}
		}
		res = min(res, now);
	}
	cout << res << "\n";
}