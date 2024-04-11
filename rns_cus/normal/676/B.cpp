#include <bits/stdc++.h>
using namespace std;

#define M 11
#define ep 1e-8

double a[M][M];
bool ok[M][M];
int n;

void add(int x, int y, double cur) {
    double tot = a[x][y] + cur, rem;
    if(tot < 1 - ep) a[x][y] = tot, rem = 0;
    else a[x][y] = 1, ok[x][y] = 1, rem = tot - 1;
    if(x == n) return;
    add(x + 1, y, rem / 2);
    add(x + 1, y + 1, rem / 2);
}

int main() {
	///freopen("b.in", "r", stdin);
	int  t;
	scanf("%d %d", &n, &t);
    for(int i = 1; i <= t; i ++) add(1, 1, 1);
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= i; j ++) if(ok[i][j]) cnt ++;
    }
    cout << cnt << endl;
}