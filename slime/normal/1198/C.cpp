#include <bits/stdc++.h>
#define maxn 500005
#define ll long long
using namespace std;
int u[maxn], v[maxn], fl[maxn]; 
int ot[maxn], ocnt;
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, m;
		scanf("%d%d", &n, &m);
		int V = 3 * n;
		for (int j = 1; j <= V; j++)
			fl[j] = 0;
		for (int j = 1; j <= m; j++)
			scanf("%d%d", &u[j], &v[j]);
		ocnt = 0;
		for (int j = 1; j <= m; j++) 
			if (!fl[u[j]] && !fl[v[j]])
				fl[u[j]] = fl[v[j]] = 1, 
				ot[ocnt++] = j;
		if (ocnt >= n) {
			printf("Matching\n");
			for (int j = 0; j < n; j++)
				printf("%d ", ot[j]);
			printf("\n");
		}
		else {
			printf("IndSet\n");
			int s = 0;
			for (int j = 1; j <= V; j++) {
				if (!fl[j]) {
					s++;
					printf("%d ", j);
					if (s >= n) break;
				}
			}
			printf("\n");
		}
		
	}
	return 0;
}