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

int main() {
	int N; ll x; cin >> N >> x;
	vector<ll> a(32, INF);
	rep(i, N) cin >> a[i];
	rep(i, 31) a[i + 1] = min(a[i + 1], a[i] * 2);
	ll sum = 0, mi = INF;
	for (int i = 31; i >= 0; i--) {
		ll y = 1LL<<i;
		if (y >= x) mi = min(mi, sum + a[i]);
		if (y <= x) x -= y, sum += a[i];
	}
	cout << mi << endl;
}