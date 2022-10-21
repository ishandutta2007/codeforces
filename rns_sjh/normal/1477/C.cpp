#include<bits/stdc++.h>
using namespace std;

#define N 5010

int x[N], y[N], n, p[N];
bool vis[N];

bool up_max(long long &a, long long b) {
    return a < b ? (a = b), 1 : 0;
}

long long dist(int i, int j) {
    return 1ll * (x[i] - x[j]) * (x[i] - x[j]) + 1ll * (y[i] - y[j]) * (y[i] - y[j]);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d%d", &x[i], &y[i]);
    p[1] = 1;
    vis[1] = 1;
    for(int i = 2; i <= n; i ++) {
        int k = p[i - 1];
        long long diameter = 0;
        int m;
        for(int j = 1; j <= n; j ++) if(!vis[j] && up_max(diameter, dist(k, j))) m = j;
        p[i] = m;
        vis[m] = 1;
    }
    for(int i = 1; i <= n; i ++) printf("%d%c", p[i], " \n"[i == n]);
}