#include <cstdio>

constexpr int maxn = 1e4+10;

int last[maxn];
struct Par { int a, b; } pares[maxn];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	int bota = (n+k-2) / (k-1), ini = 1, foi = 0;
	for(int i = 1; i <= n*k; i++) {
		int a; scanf("%d", &a);
		if(last[a] == -1) continue;
		if(last[a] < ini) last[a] = i;
		else {
			pares[a] = {last[a], i};
			last[a] = -1;
			if(++foi == bota) ini = i+1, foi = 0;
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%d %d\n", pares[i].a, pares[i].b);
}