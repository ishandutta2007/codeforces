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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll A[MAXN], SPF[MAXN], n, a, b, diff[MAXN], ps[MAXN], pref_mn[MAXN];
vector<int> P;

inline bool is_prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
	return true;
}

inline vector<int> P_Factor(int n) {
	vector<int> ans;
	for (int i = 1; i * i <= n; i++) {
		if (n % i) continue;
		if (is_prime(i)) ans.push_back(i);
		if (n / i != i && is_prime(n / i)) ans.push_back(n / i);
	}

	return ans;
}

inline void Add(int n) {
	vector<int> t = P_Factor(n);
	for (int e : t) P.push_back(e);
}

inline ll solve(ll g) {
	for (int i = 1; i <= n; i++) diff[i] = min(A[i] % g, g - A[i] % g);
	ll ans = a * n;
	bool B = true;
	for (int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1] + diff[i] * b - a;
		if (diff[i] > 1) B = false;
		pref_mn[i] = pref_mn[i - 1];
		if (B) pref_mn[i] = min(pref_mn[i], ps[i]);
	}

	for (int i = n; i >= 0; i--) {
		ans = min(ans, a * n + ps[n] - ps[i] + pref_mn[i]);
		if (diff[i] > 1) break;
	}

	return ans;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	Add(A[1]);
	Add(A[1] - 1);
	Add(A[1] + 1);
	Add(A[n]);
	Add(A[n] - 1);
	Add(A[n] + 1);

	ll ans = a * n;
	for (int e : P) ans = min(ans, solve(e));
	cout << ans << endl;
	return 0;
}