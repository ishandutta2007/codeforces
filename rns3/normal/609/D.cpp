#include <bits/stdc++.h>
using namespace std;
#define M 200010
typedef pair <int, int> PII;
#define X first
#define Y second
vector <PII> v[M];
typedef long long LL;
int n, m, K, s, nA, nB, dA, dB, aa, bb, A, B;

int a[M], b[M];

LL sA[M], sB[M];

bool check(int n) {
	A = 1e9, B = 1e9;
	for (int i = 1; i <= n; i++) {
		LL val;
		if (A > a[i]) A = a[i], dA = i;
		if (B > b[i]) B = b[i], dB = i;
	}
	for (int i = 0; i <= nA && i <= K; i++) {
		if (K - i > nB) continue;
		LL val = sA[i] * A + sB[K-i] * B; if (val <= s) {aa = i; bb = K - i; return 1;}
	}
	return 0;
}

int main() {
//	freopen("D.in", "r", stdin);
	int x, y;
	scanf("%d %d %d %d", &n, &m, &K, &s);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) scanf("%d", b + i);
    for (int i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y); v[x].push_back(PII(y, i));
    }
    for (int i = 1; i <= 2; i++) if (v[i].size()) sort(v[i].begin(), v[i].end());
    nA = v[1].size(), nB = v[2].size();
	for (int i = 1; i <= v[1].size(); i++) sA[i] = sA[i-1] + v[1][i-1].X;
	for (int i = 1; i <= v[2].size(); i++) sB[i] = sB[i-1] + v[2][i-1].X;
	bool bf = 0;
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	if (l == n + 1) puts("-1");
	else {
		printf("%d\n", r); check(r);
		for (int i = 0; i < aa; i++) printf("%d %d\n", v[1][i].Y, dA);
		for (int i = 0; i < bb; i++) printf("%d %d\n", v[2][i].Y, dB);
	}
}