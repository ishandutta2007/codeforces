#include <cstdio>

const int MAXN = 2E5 + 100, MAXM = 5E5 + 100;

int a[MAXN];
bool in[MAXN];

int len, fac[20];
int cnt[MAXM];

int DFS(int depth, int num, bool flag, int c){
	if (depth == len){
		cnt[num] += c;
		return flag ? cnt[num] : -cnt[num];
	}

	return DFS(depth + 1, num, flag, c) + DFS(depth + 1, num * fac[depth], flag ^ 1, c);
}

int main(){
	int n, Q;
	scanf("%d%d", &n, &Q);
	for (int i=1;i<=n;++i)
		scanf("%d", &a[i]);

	long long sum = 0;
	while (Q--){
		int s, t;
		scanf("%d", &s);
		t = a[s];

		len = 0;
		for (int i = 2; i * i <= t; ++i)
			if (t % i == 0)
				for (fac[len++] = i; t % i == 0; t /= i);
		if (t != 1)
			fac[len++] = t;

		if (in[s])
			sum -= DFS(0, 1, true, -1);
		else
			sum += DFS(0, 1, true, 1) - !len;
		in[s] = !in[s];

		printf("%I64d\n", sum);
	}
	return 0;
}