#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int par[N];
int find(int x) {
    return par[x] == x ?  x: par[x] = find(par[x]);
}
int n, k;
int main() {
    scanf("%d%d", &n,&k);
    for(int i=1;i<=n;i++) par[i]=i;
    int ans = 0;
    for(int i=1;i<=k;i++) {
        int u,v; scanf("%d%d", &u,&v);
        if (find(u) == find(v)) ans ++;
        par[find(u)] = find(v);
    }
    printf("%d\n", ans);
}