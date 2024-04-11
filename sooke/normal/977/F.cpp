#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Maxn 200005

#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

struct Num {
	int k, i, rnk;
};

bool Cmpk(Num A, Num B) {
	return A.k < B.k;
}
bool Cmpi(Num A, Num B) {
	return A.i < B.i;
}

Num S[Maxn];
int n, m, ans, f[Maxn], lst[Maxn], nxt[Maxn];
bool pos[Maxn];

void dfs(int d) {
	if (d == 0) {
		return;
	}
	dfs(nxt[d]);
	printf("%d ", d);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &S[i].k);
		S[i].i = i;
	}
	sort(S + 1, S + n + 1, Cmpk);
	S[0].k = -1;
	for (int i = 1; i <= n; i++) {
		if (S[i - 1].k != S[i].k) {
			S[i].rnk = ++m;
			if (S[i - 1].k + 1 == S[i].k) {
				pos[m] = true;
			}
		} else {
			S[i].rnk = m;
		}
	}
	sort(S + 1, S + n + 1, Cmpi);
	for (int i = 1; i <= n; i++) {
		if (pos[S[i].rnk]) {
			if (lst[S[i].rnk - 1] == 0) {
				f[S[i].rnk] = 1;
				lst[S[i].rnk] = i;
			} else {
				f[S[i].rnk] = f[S[i].rnk - 1] + 1;
				nxt[i] = lst[S[i].rnk - 1];
				lst[S[i].rnk] = i;
			}
		} else {
			f[S[i].rnk] = 1;
			lst[S[i].rnk] = i;
		}
		ans = Max(ans, f[S[i].rnk]);
	}
	printf("%d\n", ans);
	for (int i = n; i >= 1; i--) {
		if (f[S[i].rnk] == ans) {
			dfs(i);
			break;
		}
	}
	return 0;
}

// By Sooke.
// CF977F Consecutive Subsequence.