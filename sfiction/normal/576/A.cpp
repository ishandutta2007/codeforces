#include <cstdio>

const int MAXN = 1E3 + 10;

bool isnp[MAXN];
int cnt, cnta, a[MAXN], d[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	cnt = 0;
	cnta = 0;
	for (int i = 2; i <= n; ++i)
		if (!isnp[i]){
			d[cnt] = i;
			a[cnt] = 0;
			for (int t = n / i; t; t /= i)
				++a[cnt];
			cnta += a[cnt++];

			for (int j = i * i; j <= n; j += i)
				isnp[j] = true;
		}
	printf("%d", cnta);
	for (int i = 0; i < cnt; ++i){
		for (int t = d[i], j = 0; j < a[i]; ++j, t *= d[i])
			printf("%c%d", i || j ? ' ' : '\n', t);
	}
	puts("");
	return 0;
}