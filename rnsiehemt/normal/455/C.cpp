#include <cstdio>
#include <algorithm>
#include <vector>

int N, M, Q;
int p[300005];
int d[300005];
std::vector<int> e[300005];
bool done[300005];

int find(int a) {
    if (p[a] == a) return a;
    else return p[a] = find(p[a]);
}

void join(int a, int b) {
    p[find(b)] = find(a);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    else {
        d[a] = std::max(d[a], std::max(d[b], (d[a]+1)/2 + (d[b]+1)/2 + 1));
        p[b] = a;
    }
}

int most, mostd;
void dfs(int at, int from, int dist) {
    if (dist > mostd) {
        most = at;
        mostd = dist;
    }
    for (int i = 0; i < (int)e[at].size(); i++) {
        if (e[at][i] != from)
            dfs(e[at][i], at, dist+1);
    }
}

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 0; i < N; i++) p[i] = i;
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        join(a, b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        if (done[find(i)]) continue;
        else done[find(i)] = true;
        mostd = -1;
        dfs(i, -1, 0);
        mostd = -1;
        dfs(most, -1, 0);
        d[find(i)] = mostd;
    }
    for (int i = 0; i < Q; i++) {
        int cmd; scanf("%d", &cmd);
        if (cmd == 1) {
            int a; scanf("%d", &a); a--;
            printf("%d\n", d[find(a)]);
        }
        else {
            int a, b; scanf("%d%d", &a, &b); a--; b--;
            merge(a, b);
        }
    }
}