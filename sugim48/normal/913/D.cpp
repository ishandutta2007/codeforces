#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
struct edge { int v, w; };
const ll INF = LLONG_MAX / 2;
const int MOD = 1e9 + 7;
const ll e18 = 1e18;

vector<int> f(int N, int T, vector<int> a, vector<int> t, int k) {
	vector<i_i> v;
	rep(i, N) if (a[i] >= k) v.pb({t[i], i});
	if (v.size() < k) return {};
	sort(v.begin(), v.end());
	ll sum = 0;
	rep(i, k) sum += v[i].first;
	if (sum > T) return {};
	vector<int> ans(k);
	rep(i, k) ans[i] = v[i].second;
	return ans;
}

int main() {
	int N, T; cin >> N >> T;
	vector<int> a(N), t(N);
	rep(i, N) scanf("%d%d", &a[i], &t[i]);
	int lb = 0, ub = N + 1;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		vector<int> ans = f(N, T, a, t, mid);
		if (ans.size() == mid) lb = mid;
		else ub = mid;
	}
	vector<int> ans = f(N, T, a, t, lb);
	cout << lb << endl;
	cout << lb << endl;
	for (int i: ans) printf("%d ", i + 1);
	cout << endl;
}