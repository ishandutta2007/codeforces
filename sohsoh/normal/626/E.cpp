#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

ll ps[MAXN], A[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	sort(A + 1, A + n + 1);
	for (int i = 1; i <= n; i++)
		ps[i] = ps[i - 1] + A[i];
	
	ld ans = -MAXN;
	int tc = 0, tl = 0;

	for (int i = 1; i <= n; i++) {
		int l = 1, r = min(i - 1ll, n - i) + 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if ((ps[i] - ps[i - mid - 1] + ps[n] - ps[n - mid]) * 2 < (A[i - mid] + A[n - mid + 1]) * (mid * 2 + 1))
				l = mid + 1;
			else r = mid;
		}

		l--;
		ld tans = (ps[i] - ps[i - l - 1] + ps[n] - ps[n - l]) / ld(l * 2 + 1) - A[i];

		if (tans > ans) {
			ans = tans;
			tc = i, tl = l;
		}
	}

	cout << tl * 2 + 1 << endl;
	for (int i = tc - tl; i <= tc; i++)
		cout << A[i] << sep;
	for (int i = n - tl + 1; i <= n; i++)
		cout << A[i] << sep;
	return 0;
}