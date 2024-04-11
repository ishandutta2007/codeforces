/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 140B
 */
#include <cstdio>

const int MAXN = 300 + 10;

int n;
int pre[MAXN][MAXN];
int send[MAXN];

int main(){
	scanf("%d", &n);
	for (int i=1;i<=n+1;++i){
		pre[i % (n + 1)][0] = n << 1;
		for (int t,j=0;j<n;++j){
			scanf("%d", &t);
			pre[i % (n + 1)][t] = j;
		}
	}

	int a1 = 0, a2 = 0;
	for (int i=1;i<=n;++i)
		send[i] = 0;
	for (int i=1;i<=n;++i){
		if (pre[0][a1] > pre[0][i]){
			a2 = a1;
			a1 = i;
		}
		else if (pre[0][a2] > pre[0][i])
			a2 = i;

		for (int t,j=1;j<=n;++j){
			if (a1 == j)
				t = a2;
			else
				t = a1;

			if (pre[j][send[j]] > pre[j][t])
				send[j] = t;
		}
	}
	
	printf("%d", send[1]);
	for (int i=2;i<=n;++i)
		printf(" %d", send[i]);

	return 0;
}