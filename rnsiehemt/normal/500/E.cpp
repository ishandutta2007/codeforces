#include <bits/stdc++.h>

int N, Q;
int x[200005];
int e[200005];
int p[22][200005];
int cost[22][200005];
std::vector<int> c[200005];
int s[200005], S;
int depth[200005];

bool cmp(int a, int b) {
    return x[a] < x[b];
}

void dfs(int a, int dd) {
    depth[a] = dd;
    for (int i = 0; i < (int)c[a].size(); i++)
        dfs(c[a][i], dd+1);
}

int main()
{
    scanf("%d", &N);
    x[0] = 0; e[0] = 1000000001;
    for (int i = 1; i <= N; i++) {
        int l; scanf("%d%d", &x[i], &l);
        e[i] = x[i]+l;
    }
    N++;
    
    for (int i = N-1; i >= 0; i--) {
        while (S && e[i] >= x[s[S-1]]) {
            e[i] = std::max(e[i], e[s[S-1]]);
            p[0][s[S-1]] = i;
            c[i].push_back(s[S-1]);
            S--;
        }
        s[S++] = i;
    }
    
    for (int i = 0; i < N; i++) {
        std::sort(c[i].begin(), c[i].end(), cmp);
        int K = c[i].size();
        if (K) cost[0][c[i][K-1]] = e[i]-e[c[i][K-1]];
        for (int j = K-2; j >= 0; j--)
            cost[0][c[i][j]] = cost[0][c[i][j+1]] + x[c[i][j+1]] - e[c[i][j]];
    }

    dfs(0, 0);
    for (int j = 1; j < 22; j++) for (int i = 0; i < N; i++) {
        p[j][i] = p[j-1][p[j-1][i]];
        cost[j][i] = cost[j-1][i] + cost[j-1][p[j-1][i]];
    }

    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int x, y; scanf("%d%d", &x, &y); 
        int ans = 0;

        if (depth[x] > depth[y]) {
            for (int j = 21; j >= 0; j--) {
                if (depth[x]-(1<<j) >= depth[y]) {
                    ans += cost[j][x];
                    x = p[j][x];
                }
            }
        }
        else if (depth[y] > depth[x]) {
            for (int j = 21; j >= 0; j--)
                if (depth[y]-(1<<j) >= depth[x])
                    y = p[j][y];
        }

        if (x == y) {
            printf("0\n");
            continue;
        }

        for (int j = 21; j >= 0; j--) {
            if (p[j][x] == p[j][y]) continue;
            ans += cost[j][x];
            x = p[j][x];
            y = p[j][y];
        }

        assert(p[0][x] == p[0][y]);
        assert(x != y);

        ans += cost[0][x] - cost[0][y];
        printf("%d\n", ans);
    }
}