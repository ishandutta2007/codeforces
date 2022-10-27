#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
const LL MOD = 1e9 + 7;
LL B[62], pw[N];

bool can_ins(int x) {
	//printf("x = %d\n", x);
	for (int i = 20; i >= 0; i --) {
		if (x == 0) return false;
		if (x >> i & 1) {
			if (B[i]) {
				if (x >> i & 1) {
					x ^= B[i];
				}
			} else {
				return true;
			}
		}
	}
	//printf("end x = %d\n", x);
	return false;
}
void ins(int x) {
	//printf("ins %d\n", x);
	//for (int i = 20; i >= 0; i --) printf("%d ", B[i]); printf("\n");
	for (int i = 20; i >= 0; i --) {
		if (x == 0) return;
		if (x >> i & 1) {
			if (B[i]) {
				if (x >> i & 1) {
					x ^= B[i];
				} 
			} else {
				B[i] = x; return;
			}
		}
	}
}
int getRank() {
	int ans = 0;
	for (int i = 0; i <= 20; i ++) if (B[i]) ans ++;
	return ans;
}
int n, q;
int a[N]; LL ans[N];

vector< pair<int, int> > query[N];

int main() {
	pw[0] = 1;
	for (int i = 1; i < N; i ++) pw[i] = pw[i-1] * 2 % MOD;

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= q; i ++) {
		int l, x; scanf("%d%d", &l, &x);
		query[l].push_back(make_pair(x, i));
	}
	for (int i = 1; i <= n; i ++) {
		ins(a[i]);
		for (auto p: query[i]) {
			if (can_ins(p.first) == true) ans[p.second] = 0;
			else {
				// printf("i = %d, rk = %d\n", i, getRank());
				ans[p.second] = pw[i - getRank()];
			}
		}
	}
	for (int i = 1; i <= q; i ++) printf("%lld\n", ans[i]);
}