#include <bits/stdc++.h>
using namespace std;

#define N 20

const double ep = 1e-7;

int n, k, num[1<<N], com[N+1][N+1], M;
double p[N];
long long big[N+1];
long double func[1<<N];

int log(int k) {
	for (int i = 0; i <= N; i ++) if (k == 1 << i) return i;
	return 0;
}

void prep() {
	M = 1 << n;
	big[0] = big[1] = 1;
	for (int i = 2; i <= n; i ++) big[i] = big[i-1] * i;
    for (int i = 0; i <= n; i ++) for (int j = 0; j <= i; j ++) com[i][j] = big[i] / (big[j] * big[i-j]);
    func[0] = 0;
    num[0] = 0;
    for (int h = 1, fen; h < M; h ++) {
    	fen = h & (-h);
		num[h] = num[h-fen] + 1;
		func[h] = func[h-fen] + p[log(fen)];
    }
}

int comb(int a, int b) {
	if (b > a) return 0;
	return com[a][b];
}

int tag(int x) {
	if (x % 2) return -1;
	return 1;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i ++) scanf("%lf", &p[i]);
    prep();
    if (n == 1) {
		puts("1");
		return 0;
    }
    if (k == 1) {
		for (int i = 0; i < n - 1; i ++) printf("%lf ", p[i]);
		printf("%lf\n", p[n-1]);
		return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i ++) if (p[i] < ep) cnt ++;
    if (cnt + k >= n) {
		for (int i = 0; i < n; i ++) {
			double ans = 1;
			if (p[i] < ep) ans = 0;
			if (i == n - 1) printf("%lf\n", ans);
			else printf("%lf ", ans);
		}
		return 0;
    }
    for (int i = 0; i < n; i ++) {
        long double ans = 0;
        int now = 1 << i;
        if (p[i] > ep) for (int h = 0; h < M; h ++) if (num[h] && num[h] < k) {
            int x = num[h];
			if (h & now) ans += tag(x + k + 1) * func[h] * comb(n - x - 1, k - x - 1);
			else ans += tag(x + k + 1) * func[h] * (p[i] / (1 - func[h]) * (comb(n - x - 1, k - x - 1) - comb(n - x - 2, k - x - 2)) + comb(n - x - 2, k - x - 2));
        }
        double kk = ans;
        if (i == n - 1) printf("%.7lf\n", kk);
        else printf("%.7lf ", kk);
    }
	return 0;
}