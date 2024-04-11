#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
#define M 30
#define X first
#define Y second

int p[M], a[M][5], n, s[M], ss[M], b[M];
map <PII, PII> mp;
char type[] = "LMW";

int main() {
//	freopen("D.in", "r", stdin);
	p[0] = 1;
	for (int i = 1; i < 15; i++) p[i] = 3 * p[i-1];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) scanf("%d", &a[i][j]);
	if (n == 1) {
		int cnt = 0;
		for (int i = 0; i < 3; i++) if (!a[0][i]) b[cnt++] = i;
		if (cnt < 2) puts("Impossible");
		else {
			for (int i = 0; i < 2; i++) putchar(type[b[i]]);
		}
		return 0;
	}
	int N = n / 2;
	for (int j = 0; j < 3; j++) for (int i = N; i < n; i++) s[j] += a[i][j];
	for (int i = 0; i < p[n - N]; i++) {
		for (int j = 0; j < 3; j++) ss[j] = s[j];
		int I = i;
		for (int j = 0; j < n - N; j++) {int k = I % 3; ss[k] -= a[j+N][k]; I /= 3;}
		int x = ss[1] - ss[0], y = ss[2] - ss[1];
		if (!mp.count(PII(x, y))) mp[PII(x, y)] = PII(ss[0], i);
		else if (mp[PII(x, y)].X < ss[0]) mp[PII(x, y)] = PII(ss[0], i);
	}
	for (int j = 0; j < 3; j++) {
		s[j] = 0;
		for (int i = 0; i < N; i++) s[j] += a[i][j];
	}
	int ans = -1e9, A = -1, B = -1;
	for (int i = 0; i < p[N]; i++) {
		for (int j = 0; j < 3; j++) ss[j] = s[j];
		int I = i;
		for (int j = 0; j < N; j++) {int k = I % 3; ss[k] -= a[j][k]; I /= 3;}
		int x = ss[1] - ss[0], y = ss[2] - ss[1];
		if (mp.count(PII(-x, -y))) {
			PII t = mp[PII(-x, -y)];
			int tmp = ss[0] + t.X; if (tmp > ans) ans = tmp, A = i, B = t.Y;
		}
	}
	if (A < 0) puts("Impossible");
	else {
		for (int i = 0; i < N; i++) {
			int x = A % 3; A /= 3;
			if (x == 0) puts("MW"); else if (x == 1) puts("LW"); else puts("LM");
		}
		for (int i = 0; i < n - N; i++) {
			int x = B % 3; B /= 3;
			if (x == 0) puts("MW"); else if (x == 1) puts("LW"); else puts("LM");
		}
	}
}