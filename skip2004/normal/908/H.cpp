#include<bits/stdc++.h>
const int maxn = 100;
const int mod = 998244353;
typedef long long ll;
using std::cin;
using std::cout;
int n;
char s[maxn][maxn];
int fa[maxn], size[maxn];
int idx[maxn];
int edge[maxn];
int can[1 << 24];
int power[1 << 24];
inline int ctz(int x) { return __builtin_ctz(x); }
inline int popc(int x) { return __builtin_popcount(x); }
inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) {
		cin >> s[i] + 1;
		fa[i] = i;
		size[i] = 1;
	}
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j) {
			if(s[i][j] == 'A') {
				int x = find(i), y = find(j);
				if(x != y) {
					size[x] += size[y];
					fa[y] = x;
				}
			}
		}
	}
	int m = 0;
	for(int i = 1;i <= n;++i) if(fa[i] == i && size[i] > 1) {
		idx[i] = m ++;
	}
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j) {
			if(s[i][j] == 'X') {
				if(find(i) == find(j)) {
					puts("-1");
					exit(0);
				}
				edge[idx[find(i)]] |= 1 << idx[find(j)];
				edge[idx[find(j)]] |= 1 << idx[find(i)];
			}
		}
	}
	for(int i = 0;i < 1 << m;++i) {
		if(i & i - 1) {
			can[i] = can[i & i - 1] && (edge[ctz(i)] & i) == 0;
		} else {
			can[i] = 1;
		}
	}
	for(int mid = 1;mid < 1 << m;mid <<= 1) {
		for(int j = 0;j < 1 << m;j += mid + mid) {
			for(int k = 0;k < mid;++k) {
				can[mid + j + k] += can[j + k];
			}
		}
	}
	for(int i = 0;i < 1 << m;++i) {
		power[i] = 1;
	}
	for(int k = 1;;++k) {
		ll su = 0;
		for(int i = 0;i < 1 << m;++i) {
			power[i] = (ll) power[i] * can[i] % mod;
			su += m - popc(i) & 1 ? -power[i] : power[i];
		}
		if(su % mod) {
			cout << n - 1 + k - !m << '\n';
			return 0;
		}
	}
}