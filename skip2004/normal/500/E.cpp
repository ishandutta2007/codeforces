#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

const int N = 200100;
int n, q;

int pos[N], go[N];
int next[N], cost[N], final[N];

int jump[20][N];
int cst[20][N];

inline int max(int x, int y) {
	return go[x] > go[y] ? x : y;
}
int bit[N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> pos[i] >> go[i];
		go[i] += pos[i];
	}
	for(int i = n;i >= 1;--i) {
		next[i] = std::upper_bound(pos + 1, pos + n + 1, go[i]) - pos;
		int p = i;
		for(int x = i;x < N;x += x & -x)
			bit[x] = max(bit[x], i);
		for(int x = next[i] - 1;x;x &= x - 1)
			p = max(p, bit[x]);
		final[i] = std::max(final[p], go[p]);
		next[i] = next[p];
		cost[i] = pos[next[i]] - final[i];
	}
	rep(i, 1, n) {
		jump[0][i] = next[i];
		cst[0][i] = cost[i];
	}
	jump[0][n + 1] = n + 1;
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j <= n + 1;++j) {
			jump[i][j] = jump[i - 1][jump[i - 1][j]];
			cst[i][j] = cst[i - 1][j] + cst[i - 1][jump[i - 1][j]];
		}
	}
	cin >> q;
	rep(i, 1, q) {
		int l, r;
		cin >> l >> r;
		int res = 0;
		for(int i = 19;i >= 0;--i) {
			if(jump[i][l] <= r) {
				res += cst[i][l];
				l = jump[i][l];
			}
		}
		res += std::max(0, pos[r] - final[l]);
		cout << res << '\n';
	}
}