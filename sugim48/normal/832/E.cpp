#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

int pow_mod(ll x, ll n, int M) {
	ll ans = 1;
	for (; n; n >>= 1) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
	}
	return ans;
}

int inv[5] = {0, 1, 3, 2, 4};

int N, M;
int a[500][500], b[500][500];

void row_scale(int i, int x) {
	x = (x % 5 + 5) % 5;
	rep(j, M) a[i][j] = a[i][j] * x % 5;
	rep(j, N) b[i][j] = b[i][j] * x % 5;
}

void row_swap(int i1, int i2) {
	rep(j, M) swap(a[i1][j], a[i2][j]);
	rep(j, N) swap(b[i1][j], b[i2][j]);
}

void row_add(int i1, int i2, int x) {
	x = (x % 5 + 5) % 5;
	rep(j, M) a[i2][j] = (a[i2][j] + a[i1][j] * x) % 5;
	rep(j, N) b[i2][j] = (b[i2][j] + b[i1][j] * x) % 5;
}

int main() {
	cin >> N >> M;
	rep(i, N) {
		string s; cin >> s;
		rep(j, M) a[j][i] = s[j] - 'a';
	}
	swap(N, M);
	rep(i, N) b[i][i] = 1;
	int k = 0;
	rep(j, M) {
		int i0;
		for (i0 = k; i0 < N && !a[i0][j]; i0++);
		if (i0 == N) continue;
		row_swap(k, i0);
		row_scale(k, inv[a[k][j]]);
		rep(i, N) if (i != k) row_add(k, i, -a[i][j]);
		k++;
	}
	int Q; cin >> Q;
	while (Q--) {
		string s; cin >> s;
		vector<int> x(N);
		rep(i, N) x[i] = s[i] - 'a';
		vector<int> bx(N);
		rep(i, N) rep(j, N) bx[i] += b[i][j] * x[j];
		rep(i, N) bx[i] %= 5;
		int i0 = -1;
		rep(i, N) if (bx[i]) i0 = i;
		if (i0 < k) printf("%d\n", pow_mod(5, M - k, MOD));
		else printf("%d\n", 0);
	}
}