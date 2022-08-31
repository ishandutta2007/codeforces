#include <bits/stdc++.h>
#define maxn 200005
#define inf 200000
using namespace std;
int n;
int d[maxn], p[maxn], c[maxn]; 
bool cmp(int a, int b) {
	return d[a] > d[b];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &d[i]), 
		p[i] = i;
	sort(p + 1, p + n + 1, cmp);
	int ed = n + 1;
	for (int i = 1; i <= n; i++)
		c[i] = p[i] * 2 - 1;
	for (int i = 1; i < n; i++)
		printf("%d %d\n", c[i], c[i + 1]);
	for (int i = 1; i <= n; i++)
		if (i + d[p[i]] < ed)
			printf("%d %d\n", c[i] + 1, c[i + d[p[i]] - 1]);
		else
			printf("%d %d\n", c[i] + 1, c[ed - 1]), 
			c[ed++] = c[i] + 1;
	return 0;
}