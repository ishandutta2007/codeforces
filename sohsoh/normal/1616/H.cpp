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
const ll LOG = 30;
const ll MOD = 998244353;

int n, x;
ll pw[MAXN];

inline pair<vector<int>, vector<int>> orz(vector<int>& A, int i) {
	vector<int> ans[2];
	for (int x : A)
		ans[x >> i & 1].push_back(x);

	return {ans[0], ans[1]};
}

inline ll g(vector<int> A, vector<int> B, int i) {
	if (A.empty() || B.empty()) return 0;
	if (i < 0) return (pw[A.size()] - 1) * (pw[B.size()] - 1) % MOD;
	vector<int> A0, A1, B0, B1;
	tie(A0, A1) = orz(A, i);
	tie(B0, B1) = orz(B, i);

	if (x >> i & 1) {
		ll g0 = g(A0, B1, i - 1) , g1 = g(A1, B0, i - 1);
		return (g0 * g1 + g0 * (pw[A1.size()] + pw[B0.size()] - 1) +
			g1 * (pw[A0.size()] + pw[B1.size()] - 1) + (pw[A0.size()] - 1) * (pw[B0.size()] - 1) + 
			(pw[A1.size()] - 1) * (pw[B1.size()] - 1)) % MOD;
	} else {
		return (g(A0, B0, i - 1) + g(A1, B1, i - 1)) % MOD;
	}
}

inline ll f(vector<int> A, int i) {
	if (A.empty()) return 0;
	if (i < 0) return pw[A.size()] - 1;

	vector<int> A0, A1;
	tie(A0, A1) = orz(A, i);

	if (x >> i & 1) {
		return (pw[A0.size()] - 1 + pw[A1.size()] - 1 + g(A0, A1, i - 1)) % MOD;
	} else {
		return (f(A0, i - 1) + f(A1, i - 1)) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	for (int i = 1; i < MAXN; i++)
		pw[i] = pw[i - 1] * 2 % MOD;

	cin >> n >> x;
	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}

	cout << f(vec, LOG) << endl;
	return 0;
}