#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
typedef long long ll;
typedef pair<int, int> i_i;

int pow_mod(ll x, ll n, int M) {
	ll ans = 1;
	for (; n; n>>=1) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
	}
	return ans;
}

int inv_mod(int x, int p) {
	return pow_mod(x, p - 2, p);
}

vector<vector<int>> f(vector<vector<int>> a, int MOD) {
	int N = a.size(), M = a[0].size();
	int k = 0;
	rep(j, M) {
		int i0;
		for (i0 = k; i0 < N && !a[i0][j]; i0++);
		if (i0 == N) continue;
		swap(a[k], a[i0]);
		int x = inv_mod(a[k][j], MOD);
		rep(j, M) a[k][j] = (ll)a[k][j] * x % MOD;
		rep(i, N) if (i != k) {
			int x = a[i][j];
			rep(j, M) a[i][j] = (a[i][j] - (ll)a[k][j] * x) % MOD;
		}
		k++;
	}
	while (N) {
		bool ok = true;
		rep(j, M) if (a[N - 1][j]) ok = false;
		if (ok) N--, a.pop_back();
		else break;
	}
	rep(i, N) rep(j, M) a[i][j] = (a[i][j] + MOD) % MOD;
	return a;
}

int main() {
	int T, M; cin >> T >> M;
	map<pair<vector<vector<int>>, vector<vector<int>>>, vector<int>> mp;
	rep(t, T) {
		int N; scanf("%d", &N);
		vector<vector<int>> a(N, vector<int>(M));
		rep(i, N) rep(j, M) scanf("%d", &a[i][j]);
		vector<vector<int>> b = f(a, 1e9 + 7);
		vector<vector<int>> c = f(a, 1e9 + 9);
		mp[{b, c}].push_back(t);
	}
	vector<int> ans(T);
	int K = 0;
	for (auto z: mp) {
		for (int t: z.second) ans[t] = K;
		K++;
	}
	vector<int> mi(K, INT_MAX);
	rep(t, T) mi[ans[t]] = min(mi[ans[t]], t);
	vector<i_i> v(K);
	rep(k, K) v[k] = {mi[k], k};
	sort(v.begin(), v.end());
	rep(k, K) mi[v[k].second] = k;
	rep(t, T) printf("%d ", mi[ans[t]] + 1);
	cout << endl;
}