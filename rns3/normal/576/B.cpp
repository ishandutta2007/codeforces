#include <bits/stdc++.h>
using namespace std;
#define M 100010
int p[M], vis[M], n, m, d[M], id[M];
vector <int> v[M];

bool cmp(int i, int j) {return d[i] < d[j];}

int main() {
//	freopen("B.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    if (n == 1) return puts("YES"), 0;
    else if (n == 2) {
    	puts("YES"); printf("%d %d\n", 1, 2); return 0;
    }
    for (int i = 1; i <= n; i++) if (i == p[i]) {
    	puts("YES");
		for (int j = 1; j <= n; j++) if (j != i) printf("%d %d\n", i, j);
		return 0;
    }
    for (int i = 1; i <= n; i++) {
    	if (vis[i]) continue;
		int j = i;
		++m; while (!vis[j]) {v[m].push_back(p[j]); vis[j] = 1; j = p[j];}
    }
    if (m == 1) return puts("NO"), 0;
    for (int i = 1; i <= m; i++) d[i] = v[i].size(), id[i] = i;
    sort(id + 1, id + m + 1, cmp);
	bool bf = 0;
    for (int i = 2; i <= m; i++) if (d[id[i]] % 2) {bf = 1; break;}
    if (bf || d[id[1]] > 2) return puts("NO"), 0;
    puts("YES");
    for (int i = 2; i <= m; i++) {
    	int J = id[i];
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < (d[J] / 2); k++) {
				printf("%d %d\n", v[id[1]][j], v[J][k*2+j]);
			}
		}
    }
    printf("%d %d\n", v[id[1]][0], v[id[1]][1]);
}