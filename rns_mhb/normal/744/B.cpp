#include <bits/stdc++.h>
using namespace std;

#define N 1005
#define K 10
#define INF 1000000005

int n, m;
int ans[N];
int mn[3][K+5][N];
vector<int> v[3][K+5];
int c[K+5];

void init() {
    for (int i = 0; i < n; i ++) {
        int x = i;
        for (int j = 0; j < K; j ++) {
            c[j] = x & 1;
            x /= 2;
            v[c[j]][j].push_back(i);
        }
    }
}

int main() {
    scanf("%d", &n);
    init();
    for (int i = 0; i < 2; i ++)
    for (int j = 0; j < K; j ++)
    for (int k = 0; k < n; k ++) mn[i][j][k] = INF;
    for (int i = 0; i < 2; i ++)
    for (int j = 0; j < K; j ++) {
        if (v[i][j].empty()) continue;
        printf("%d\n", (int)v[i][j].size());
        fflush(stdout);
        for (int k = 0; k < v[i][j].size(); k ++) {
            printf("%d ", v[i][j][k] + 1);
            fflush(stdout);
        }
        puts("");
        fflush(stdout);
        for (int k = 0; k < n; k ++) {
            int x;
            scanf("%d", &mn[i][j][k]);
        }
    }
    for (int i = 0; i < n; i ++) {
        int x = i;
        ans[i] = INF;
        for (int j = 0; j < K; j ++) {
            c[j] = x & 1; x /= 2;
            ans[i] = min(ans[i], mn[!c[j]][j][i]);
        }
    }
    printf("-1\n");
    fflush(stdout);
    for (int i = 0; i < n; i ++) {
        printf("%d ", ans[i]);
        fflush(stdout);
    }
}