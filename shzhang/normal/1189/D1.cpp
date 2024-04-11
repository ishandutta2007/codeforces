#include <cstdio>

using namespace std;

int degree[100005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        degree[u]++; degree[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 2) {
            printf("NO"); return 0;
        }
    }
    printf("YES"); return 0;
}