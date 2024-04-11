#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n;
ll A[MAXN], ps[MAXN], T[MAXN];

inline bool check(int i, int x) {
	if (T[i] > x) return false;
	if ((ps[n] + i - 1) / i > x) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ps[i] = ps[i - 1] + A[i];
		T[i] = max(T[i - 1], (ps[i] + i - 1) / i);
	}

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (!check(n, x)) cout << -1 << endl;
		else {
			int l = 1, r = n;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (check(mid, x)) r = mid;
				else l = mid + 1;
			}

			cout << l << endl;
		}
	}
	return 0;
}