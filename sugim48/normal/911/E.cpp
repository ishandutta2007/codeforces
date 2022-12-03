#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;

struct bit {
	vector<ll> v;
	bit(int n) : v(n + 1) {}
	ll sum(int i) {
		ll res = 0;
		for (; i > 0; i -= i & -i) res += v[i];
		return res;
	}
	void add(int i, ll x) {
		for (i++; i < v.size(); i += i & -i) v[i] += x;
	}
};

int main() {
	int N, K; cin >> N >> K;
	vector<int> p;
	vector<bool> used(N);
	while (K--) {
		int x; scanf("%d", &x), x--;
		p.pb(x);
		used[x] = true;
	}
	vector<int> v;
	v.pb(-1);
	rep(x, N) if (used[x]) v.pb(x);
	v.pb(N);
	for (int j = 0; j + 1 < v.size(); j++) {
		int l = v[j], r = v[j + 1];
		for (int x = r - 1; x >= l + 1; x--) p.pb(x);
	}
	vector<int> b(N);
	bit bt(N);
	for (int x: p) {
		b[x] = bt.sum(N) - bt.sum(x);
		bt.add(x, 1);
	}
	rep(x, N - 1) if (b[x] - b[x + 1] > 1) {
		cout << -1 << endl;
		return 0;
	}
	for (int x: p) printf("%d ", x + 1);
	cout << endl;
}