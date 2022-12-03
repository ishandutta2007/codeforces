#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, int> d_i;
const int MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
struct edge { int i, v, w; };

struct unko { int i, s, h; };

bool cmp(const unko& x, const unko& y) {
	return (ll)x.s * y.h > (ll)y.s * x.h;
}

int main() {
	int N; cin >> N;
	vector<string> a(N);
	rep(i, N) cin >> a[i];
	vector<unko> b(N);
	rep(i, N) {
		b[i].i = i;
		for (char c: a[i]) {
			if (c == 's') b[i].s++;
			if (c == 'h') b[i].h++;
		}
	}
	sort(b.begin(), b.end(), cmp);
	ll ans = 0, S = 0;
	rep(_i, N) {
		int i = b[_i].i;
		for (char c: a[i]) {
			if (c == 's') S++;
			if (c == 'h') ans += S;
		}
	}
	cout << ans << endl;
}