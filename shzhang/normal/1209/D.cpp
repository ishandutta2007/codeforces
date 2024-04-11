#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

int uf[100005];
int find(int a)
{
    return uf[a] == a ? a : uf[a] = find(uf[a]);
}

void un(int a, int b)
{
    a = find(a); b = find(b);
    uf[a] = b;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) uf[i] = i;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (find(x) == find(y)) ans++;
        else un(x, y);
    }
    printf("%d", ans);
    return 0;
}