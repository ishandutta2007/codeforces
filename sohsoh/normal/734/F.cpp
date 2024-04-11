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
const ll LOG = 31;

ll s, B[MAXN], C[MAXN], n, A[MAXN], cnt[LOG];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> B[i];
		s += B[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> C[i];
		s += C[i];
	}

	if (s % (2 * n)) return cout << -1 << endl, 0;
	s = s / (2 * n);

	for (int i = 1; i <= n; i++) {
		A[i] = B[i] + C[i] - s;
		if (A[i] % n) return cout << -1 << endl, 0;
		A[i] /= n;

		for (int j = 0; j < LOG; j++)
			if (A[i] & (1ll << j))
				cnt[j]++;
	}


	for (int i = 1; i <= n; i++) {
		ll tb = 0;
		for (int j = 0; j < LOG; j++)
			if ((A[i] & (1ll << j)))
				tb += cnt[j] * (1ll << j);
		if (tb != B[i]) return cout << -1 << endl, 0;
	}

	for (int i = 1; i <= n; i++) cout << A[i] << sep;
	cout << endl;
	return 0;
}