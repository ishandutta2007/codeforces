#include <bits/stdc++.h>

int N, M;
std::vector<int> e[100005];
int p[100005];
bool cycle[100005];
bool seen[100005];
bool par[100005];
int ans;

int find(int a) {
    if (p[a] == a) return a;
    else return p[a] = find(p[a]);
}

void join(int a, int b) {
    cycle[find(b)] |= cycle[find(a)];
    p[find(a)] = find(b);
}

void dfs(int i, int rr) {
    int r = find(rr);
    seen[i] = true;
    par[i] = true;
    for (int j = 0; j < (int)e[i].size(); j++) {
        int k = e[i][j];
        if (find(k) == r) {
            if (par[k]) {
                if (!cycle[r]) {
                    cycle[r] = true;
                    ans++;
                }
            }
            // else do nothing
        }
        else {
            if (!(cycle[find(k)] && cycle[r]))
                ans++;
            join(k, r);
        }
        if (!seen[k]) dfs(k, rr);
    }
    par[i] = false;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        e[a].push_back(b);
    }

    for (int i = 0; i < N; i++)
        p[i] = i;

    for (int i = 0; i < N; i++)
        if (!seen[i])
            dfs(i, i);

    printf("%d\n", ans);
}