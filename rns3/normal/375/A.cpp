#include <bits/stdc++.h>
using namespace std;
#define M 1001001

int n;
char s[M];
int p[M] = {1};
int v[10][M], deg[M];
int Rand() { return rand() * rand(); }

int main() {
	//freopen("A.in", "r", stdin);
	scanf("%s", s);
	n = strlen(s);
	for (int i = 1; i <= n; i++) {
		p[i] = p[i-1] * 10 % 7;
	}
	int rlt = 0;
	reverse(s, s + n);
	for (int i = 0; s[i]; i++) {
		int c = s[i] - '0';
		rlt = (rlt + p[i] * c) % 7;
		v[c][deg[c]++] = i;
	}

	while (rlt) {
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
        if (x == y || !deg[x] || !deg[y]) {
			continue;
        }
        int tx = Rand() % deg[x];
        int ty = Rand() % deg[y];
        swap(v[x][tx], v[y][ty]);
        //printf("x = %d, y = %d; %d, %d\n", x, y, v[x][tx], v[y][ty]);
        s[v[x][tx]] = x + '0';
        s[v[y][ty]] = y + '0';
        rlt = rlt + (p[v[x][tx]] - p[v[y][ty]]) * (x - y);
        rlt %= 7;
        if (rlt < 0) rlt += 7;
	}

	reverse(s, s + n);

	puts(s);
	return 0;
}