#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n, ans;
vector<int> v[N];
int vis[N];

void init() {
    for (int i = 2; i < N - 2; i ++) {
        for (int j = 1; i * j < N - 2; j ++) {
            v[j*i].push_back(i);
        }
    }
}

int main() {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < v[x].size(); j ++) {
            vis[v[x][j]] ++;
        }
    }
    for (int i = 2; i < N - 2; i ++) ans = max(ans, vis[i]);
    printf("%d\n", max(ans, 1));
}