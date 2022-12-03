#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

const int MOD = 1e9 + 7;
const ll INF = INT_MAX;

int main() {
	int N, M; cin >> N >> M;
	ll x0; cin >> x0;
	vector<ll> a(N);
	rep(i, N) cin >> a[i];
	sort(a.begin(), a.end());
	vector<ll> b(M);
	rep(j, M) cin >> b[j];
	ll lb = -1, ub = INF;
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		vector<int> l(M, N), r(M, 0);
		rep(j, M)
			rep(i, N) if (abs(a[i] - b[j]) + abs(x0 - b[j]) <= mid)
				l[j] = min(l[j], i), r[j] = max(r[j], i + 1);
		vector<bool> used(M);
		bool ok = true;
		rep(i, N) {
			int j0 = -1, R = N + 1;
			rep(j, M) if (!used[j] && l[j] <= i && i < r[j])
				if (r[j] < R) j0 = j, R = r[j];
			if (j0 == -1) ok = false;
			else used[j0] = true;
		}
		if (ok) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
}