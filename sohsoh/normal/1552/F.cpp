// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll MOD = 998244353;

ll F[MAXN], X[MAXN], Y[MAXN], O[MAXN], ps[MAXN], n;
vector<int> v;
bool T[MAXN], A[MAXN];

inline int point(int x) {
	return lower_bound(all(v), x) - v.begin();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> X[i] >> Y[i] >> T[i];
		v.push_back(X[i]);
		v.push_back(Y[i]);
	}	

	v.push_back(0);
	sort(all(v));

	for (int i = 1; i <= n; i++) {
		O[point(X[i])] = point(Y[i]);
		A[point(X[i])] = T[i];
	}

	ll ans = v.back() + 1;
	for (int i = 0; i < v.size(); i++) {
		if (O[i]) {
			F[i] = (ps[i - 1] - ps[O[i]] + v[i] - v[O[i]] + 3 * MOD) % MOD;
			if (A[i]) ans = (ans + F[i]) % MOD;
		}

		ps[i] = (ps[i - 1] + F[i]) % MOD;
	}

	cout << ans % MOD << endl;
	return 0;
}