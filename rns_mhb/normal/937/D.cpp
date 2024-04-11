#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define N 100005

vector <int> v[N];
bool vis[N][2];
int ris[N];

int n, m, c[N];
int p[N][2];

void dfs(int k, int d, int pa = 0) {
    vis[k][d] = 1; p[k][d] = pa;
    for (auto x : v[k]) {
        if (vis[x][d^1]) continue;
        dfs(x, d^1, k);
    }
    return;
}

bool efs(int k) {
    ris[k] = 1;
    for (auto x : v[k]) {
        if (!ris[x]) {
			if (efs(x)) return 1;
        }
        else if (ris[x] == 1) return 1;
        else continue;
    }
    ris[k] = 2;
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    int x, y;
    f1(i, 1, n) {
        scanf("%d", &c[i]);
        f1(j, 1, c[i]) scanf("%d", &x), v[i].pb(x);
    }
    int pos;
    scanf("%d", &pos);
    dfs(pos, 0);
    f1(i, 1, n) if (c[i] == 0 && vis[i][1]) {
        puts("Win");
        x = i, y = 1;
        stack <int> stk;
        while (p[x][y]) {
			stk.push(x);
            x = p[x][y]; y ^= 1;
        }
        stk.push(x);
        while (!stk.empty()) {
            y = stk.top(); stk.pop();
            printf("%d ", y);
        }
        return 0;
    }
    if (efs(pos)) puts("Draw");
    else puts("Lose");
	return 0;
}