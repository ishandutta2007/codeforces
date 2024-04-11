#include<bits/stdc++.h>
using namespace std;

#define N 100010

struct edge {
    int x, y, z;
    edge(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
    bool operator < (const edge &e) const {return z < e.z;}
    void in() {scanf("%d%d%d", &x, &y, &z);}
} e[N];

int v[N], p[N];

int find_rt(int x) {
    return x == p[x] ? x : p[x] = find_rt(p[x]);
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1, x; i <= k; i ++) {
        scanf("%d", &x);
        v[x] = 1;
    }
    for(int i = 1; i <= n; i ++) p[i] = i;
    for(int i = 1; i <= m; i ++) e[i].in();
    sort(e + 1, e + m + 1);
    for(int i = 1; i <= m; i ++) {
        int x = find_rt(e[i].x), y = find_rt(e[i].y);
        if(x == y) continue;
        p[y] = x;
        v[x] += v[y];
        if(v[x] == k) {
            while(k --) printf("%d ", e[i].z);
            puts("");
            return 0;
        }
    }
}