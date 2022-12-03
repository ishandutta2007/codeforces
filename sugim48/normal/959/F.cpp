#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
const int MOD = 1e9 + 7;

int project(vector<int> B, int x) {
	for (int y: B) x = min(x, x ^ y);
	return x;
}

int main() {
	int N, Q; cin >> N >> Q;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<vector<i_i>> queries(N);
	rep(q, Q) {
		int l, x; scanf("%d%d", &l, &x);
		queries[l - 1].pb({q, x});
	}
	vector<int> B;
	int unko = 1;
	vector<int> ans(Q);
	rep(i, N) {
		int x = project(B, a[i]);
		if (x) B.pb(x), sort(B.rbegin(), B.rend());
		else unko = unko * 2 % MOD;
		for (i_i z: queries[i]) if (!project(B, z.second)) ans[z.first] = unko;
	}
	rep(q, Q) printf("%d\n", ans[q]);
}