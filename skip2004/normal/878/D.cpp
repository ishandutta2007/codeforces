#include<bits/stdc++.h>
#define pb push_back
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;
typedef long long ll;
const int maxn = 100100;
std::bitset<4096> set[maxn];
int n, k, q;
int a[30][maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k >> q;
	rep(i, 1, k) rep(j, 1, n) cin >> a[i][j];
	for(int i = 0;i < 1 << k;++i) {
		for(int j = 1;j <= k;++j) {
			if(i >> j - 1 & 1) {
				set[j].set(i);
			}
		}
	}
	int idx = k;
	for(int i = 0, tp, x, y;i < q;++i) {
		cin >> tp >> x >> y;
		if(tp == 1) {
			set[++idx] = set[x] | set[y];
		} else if(tp == 2) {
			set[++idx] = set[x] & set[y];
		} else {
			int ans = 0, out = 0;
			for(;;) {
				int nxt = -1;
				for(int j = 0;j < k;++j) if(!(ans >> j & 1) && (nxt == -1 || a[j + 1][y] > a[nxt + 1][y])) 
					nxt = j;
				if(nxt == -1) break;
				ans |= 1 << nxt;
				out = a[nxt + 1][y];
				if(set[x].test(ans)) break;
			}
			cout << out << '\n';
		}
	}
}