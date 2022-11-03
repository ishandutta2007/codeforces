#include <cstdio>

const int MAXN = 1E5 + 10;

int l[MAXN], r[MAXN];
double p[MAXN];

int main(){
	int n, P;
	scanf("%d%d", &n, &P);
	double ans = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &l[i], &r[i]);
		p[i] = (r[i] / P - (l[i] - 1) / P) / (double)(r[i] - l[i] + 1);
		ans += 2 * p[i];
	}
	p[n] = p[0];
	for (int i = 0; i < n; ++i)
		ans -= p[i] * p[i + 1];
	ans *= 2000;
	printf("%.12f\n", ans);
	return 0;
}