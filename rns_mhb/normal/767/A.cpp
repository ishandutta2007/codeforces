#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n;
bool vis[N];

int main() {
    scanf("%d", &n);
    for (int i = 1, j = n; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        vis[x] = 1;
        while (j > 0 && vis[j]) {
            printf("%d ", j --);
        }
        puts("");
    }
    return 0;
}