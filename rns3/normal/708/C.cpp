#include <bits/stdc++.h>
using namespace std;
#define M 400400

int n;
vector<int> v[M];
int mx[M], chi[M];

void input() {
    scanf("%d", &n);
    for (int x, y, i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

int root;
void dfs(int x, int f) {
    chi[x] = 1;
    for (int y, i = 0; i < v[x].size(); i++) {
        if ((y = v[x][i]) == f) continue;
        dfs(y, x);
        chi[x] += chi[y];
        mx[x] = max(mx[x], chi[y]);
    }
    mx[x] = max(mx[x], n - chi[x]);
    //printf("mx[%d] = %d\n", x, mx[x]);
    if (mx[x] <= n / 2) {
        if (root) {
            for (int i = 1; i <= n; i++) printf("1%c", i == n ? '\n' : ' ');
            puts("");
            exit(0);
        }
        root = x;
    }
}

int flag[M];
void DFS(int x, int f) {
    chi[x] = 1;
    for (int y, i = 0; i < v[x].size(); i++) {
        if ((y = v[x][i]) == f) continue;
        DFS(y, x);
        chi[x] += chi[y];
    }
}

int A, B;
int top;
void dfs1(int x, int f) {
    for (int y, i = 0; i < v[x].size(); i++) {
        if ((y = v[x][i]) == f) continue;
        dfs1(y, x);
    }
    int mx = A;
    if (chi[top] == A) mx = B;
    if (n - chi[x] - mx <= n / 2) flag[x] = 1;
}

int main() {
    //freopen("C3.in", "r", stdin);
    input();
    dfs(1, 0);

    //printf("root = %d\n", root);
    flag[root] = 1;
    memset(chi, 0, sizeof chi);
    DFS(root, 0);


    for (int x, i = 0; i < v[root].size(); i++) {
        x = v[root][i];
        if (chi[x] > A) B = A, A = chi[x];
        else if (chi[x] > B) B = chi[x];
    }
    for (int x, i = 0; i < v[root].size(); i++) {
        x = v[root][i];
        top = x;
        dfs1(x, root);
    }

    for (int i = 1; i <= n; i++) printf("%d%c", flag[i], i == n ? '\n' : ' ');
    return 0;
}