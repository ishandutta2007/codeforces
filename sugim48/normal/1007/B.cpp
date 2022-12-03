#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

vector<vector<int>> ds;
vector<int> D;

/*
int solve(int A, int B, int C) {
	vector<vector<int>> p = {
		{A, B, C},
		{A, C, B},
		{B, A, C},
		{B, C, A},
		{C, A, B},
		{C, B, A}
	};
	int ans = 0;
	rep(S, 1<<6) if (S) {
		vector<int> x(3);
		rep(k, 6) if (S>>k & 1) rep(i, 3) x[i] = gcd(x[i], p[k][i]);
		int tot;
		if (memo.count(x)) tot = memo[x];
		else {
			vector<int> &a = ds[x[0]];
			vector<int> &b = ds[x[1]];
			vector<int> &c = ds[x[2]];
			int N = a.size(), M = b.size(), L = c.size();
			vector<int> dp(M);
			int i = 0;
			rep(j, M) {
				for (; i < N && a[i] <= b[j]; i++);
				dp[j] = i;
			}
			int j = 0, sum = 0;
			tot = 0;
			rep(l, L) {
				for (; j < M && b[j] <= c[l]; j++) sum += dp[j];
				tot += sum;
			}
			memo[x] = tot;
		}
		rep(k, 6) if (S>>k & 1) tot *= -1;
		ans += tot;
	}
	return -ans;
}
*/

int solve(int A, int B, int C) {
	vector<int> unko = {A, B, C};
	vector<int> a(1<<3);
	rep(S, 1<<3) {
		int d = 0;
		rep(i, 3) if (S>>i & 1) d = gcd(d, unko[i]);
		a[S] = D[d];
	}
	vector<vector<int>> p = {
		{1, 2, 4},
		{1, 4, 2},
		{2, 1, 4},
		{2, 4, 1},
		{4, 1, 2},
		{4, 2, 1}
	};
	int n1 = 0, n2 = 0, n3 = 0;
	rep(S, 1<<6) if (S) {
		int sign = 1;
		vector<int> x(3);
		rep(k, 6) if (S>>k & 1) {
			sign *= -1;
			rep(i, 3) x[i] |= p[k][i];
		}
		n1 += sign * a[x[0] | x[1] | x[2]];
		n2 += sign * a[x[0] | x[1]] * a[x[2]] * 3;
		n3 += sign * a[x[0]] * a[x[1]] * a[x[2]];
	}
	n2 -= n1 * 3;
	n3 -= n1 + n2;
	return -(n1 + n2 / 3 + n3 / 6);
}

int naive(int A, int B, int C) {
	vector<vector<int>> v;
	for (int x: ds[A]) for (int y: ds[B]) for (int z: ds[C]) {
		vector<int> p = {x, y, z};
		sort(p.begin(), p.end());
		v.pb(p);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v.size();
}

int main() {
	ds.resize(100001);
	for (int x = 1; x <= 100000; x++) {
		for (int y = 1; y * y <= x; y++)
			if (x % y == 0) {
				ds[x].pb(y);
				if (y * y < x) ds[x].pb(x / y);
			}
		sort(ds[x].begin(), ds[x].end());
	}
	D.resize(100001);
	for (int x = 1; x <= 100000; x++)
		D[x] = ds[x].size();
	/*
	for (int A = 1; A <= 30; A++)
		for (int B = 1; B <= 30; B++)
			for (int C = 1; C <= 30; C++) {
				cout << A << ' ' << B << ' ' << C << endl;
				int x = solve(A, B, C);
				int y = naive(A, B, C);
				if (x != y) cout << "ERR" << endl;
			}
	return 0;
	*/
	int T; cin >> T;
	while (T--) {
		int A, B, C; scanf("%d%d%d", &A, &B, &C);
		// solve(A, B, C);
		printf("%d\n", solve(A, B, C));
	}
}