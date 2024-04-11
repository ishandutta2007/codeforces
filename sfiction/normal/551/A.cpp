/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 551A
 */
#include <cstdio>

const int MAXN = 2E3 + 100;

int n, a[MAXN];

int main(){
	scanf("%d", &n);
	for (int i=0;i<n;++i)
		scanf("%d", &a[i]);
	for (int i=0;i<n;++i){
		int rank = 1;
		for (int j=0;j<n;++j)
			rank += a[i] < a[j];
		printf("%d%c", rank, i == n - 1 ? '\n' : ' ');
	}

	return 0;
}