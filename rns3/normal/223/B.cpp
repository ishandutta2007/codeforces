#include <bits/stdc++.h>
using namespace std;
#define M 300001
#define N 27

int gas[M][N];
char s[M], t[M];
int f[M], g[M];

bool find(int x, int y, int z) {
	if(x > y) return 0;
    return gas[y][z] > gas[x-1][z];
}

int main() {
	///freopen("2.in", "r", stdin);
    scanf("%s %s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    f[0] = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = f[i-1];
		if(f[i-1] < m && s[i] == t[f[i-1] + 1]) f[i] ++;
    }
    g[n+1] = m+1;
    for(int i = n; i; i --){
    	g[i] = g[i+1];
		if(g[i] > 1 && s[i] == t[g[i] - 1]) g[i] --;
    }
    for(int i = 1; i <= m; i ++) {
    	for(int j = 0; j < 26; j ++) gas[i][j] = gas[i-1][j];
		gas[i][t[i] - 'a'] ++;
    }
    for(int i = 1; i <= n; i ++) {
        int x = f[i - 1], y = g[i + 1];
        if(!find(max(y - 1, 1),  min(x + 1, m),  s[i] - 'a')) return puts("NO");
    }
    return puts("YES");
}