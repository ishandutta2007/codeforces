#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

void wt(long long x) {
	if (x >= 10) wt(x / 10);
	putchar(x % 10 + 48);
}

const int N = 3e6 + 10;
struct num {
	int p, q;
	bool operator < (const num &t) const {
		return p < t.p;
	}
};
struct Fac {
	num k[20]; int tot;
	void clear() {
		for (int i = 0; i < 20; i ++) k[i].q = k[i].p = 0;
		tot = 0;
	}
	void sort() { ::sort(k + 1, k + tot + 1); }
}A, B, C;
int pri[N], mf[N], n1, n2, n3, s1, s2, s3, m1, m2, m3;
long long n, m, s, ans;

void getp() {
	int n = 3e6;
	for (int i = 2; i <= n; i ++) {
		if (!mf[i]) mf[i] = i, pri[++pri[0]] = i;
		for (int j = 1; j <= pri[0] && i * pri[j] <= n; j ++) {
			mf[i * pri[j]] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}

int id[N];
void facor(Fac &a, int x) {
	for(; mf[x]; x /= mf[x]) {
		if (!id[mf[x]]) id[mf[x]] = ++ a.tot, a.k[a.tot].p = mf[x];
		a.k[id[mf[x]]].q ++;
	}
}

void dfs(int u, long long sum) {
	if (sum > n) return;
	if (u > C.tot) { ans ++; return; }
	dfs(u + 1, sum);
	for (int i = 1; i <= C.k[u].q; i ++) sum *= C.k[u].p, dfs(u + 1, sum);
}

void dfs2(int x, long long y, int z) {
	if (!y) return;
	if (x > B.tot) { ans += y * z; return;}
	dfs2(x + 1, y, z);
	for (int i = 0; i <= B.k[x].q; i ++) y /= B.k[x].p;
	dfs2(x + 1, y, -z);
}

int main() {
	getp();
	for (int T = rd(); T; T --) {
		ans = 0, A.clear(), B.clear(), C.clear();
		n1 = rd(), n2 = rd(), n3 = rd(), n = 1ll * n1 * n2 * n3; 
		m1 = rd(), m2 = rd(), m3 = rd(), m = 1ll * m1 * m2 * m3; 
		s1 = rd(), s2 = rd(), s3 = rd(), s = 1ll * s1 * s2 * s3; 
		memset(id, 0, sizeof id);
		facor(A, n1), facor(A, n2), facor(A, n3);
		memset(id, 0, sizeof id);
		facor(C, 2 * s1), facor(C, s2), facor(C, s3);
		A.sort(), C.sort(); 
		dfs(1, 1);
		int i = 1, j = 1;
		while (i <= A.tot && j <= C.tot) {
			if (A.k[i].p == C.k[j].p) {
				if (A.k[i].q > C.k[j].q) B.k[++B.tot].p = C.k[j].p, B.k[B.tot].q = C.k[j].q;
				i ++, j ++;
				continue;
			}
			if (A.k[i].p < C.k[j].p) {
				B.k[++B.tot].p = A.k[i].p, B.k[B.tot].q = 0;
				i ++;
				continue;
			}
			j ++;
		}
		for (; i <= A.tot; i ++) B.k[++B.tot].p = A.k[i].p, B.k[B.tot].q = 0;
		dfs2(1, m, 1);
		wt(ans), putchar(10);
	}
	return 0;
}