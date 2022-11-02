#include<bits/stdc++.h>
using namespace std;

#define N 1000010

struct edge {
    int x, y, z;
    bool operator < (const edge &e) const {return z < e.z;}
    void in() {scanf("%d%d%d", &x, &y, &z);}
} e[N];

int f[N];
int find_rt(int x) {return f[x]==x?x:f[x]=find_rt(f[x]);}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) e[i].in();
    sort(e + 2, e + m + 1);
    for(int i = 1; i <= m; i ++) f[i] = i;
    int u = e[1].x, v = e[1].y;
    for(int i = 2; i <= m; i ++) {
        int x = find_rt(e[i].x), y = find_rt(e[i].y);
        f[x] = y;
        if(find_rt(u) == find_rt(v)) return printf("%d\n", e[i].z), 0;
    }
    puts("1000000000");
}