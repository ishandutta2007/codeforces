#include <bits/stdc++.h>

int N;
int p[305];
int e[305][305];
int q[305]; int Q;
int u[305];
int pp[305];
bool seen[305];

void dfs(int a) {
    if (seen[a]) return;
    else seen[a] = true;
    q[Q++] = a;
    for (int i = 0; i < N; i++)
        if (e[a][i])
            dfs(i);
}

bool cmp(int a, int b) {
    return p[a] < p[b];
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        char a; scanf(" %c", &a);
        e[i][j] = (a == '1');
    }

    for (int i = 0; i < N; i++) {
        if (!seen[i]) {
            Q = 0;
            dfs(i);
            for (int j = 0; j < Q; j++) u[j] = q[j];
            std::sort(q, q+Q);
            std::sort(u, u+Q, cmp);
            for (int j = 0; j < N; j++) pp[j] = p[j];
            for (int j = 0; j < Q; j++) pp[q[j]] = p[u[j]];
            for (int j = 0; j < N; j++) p[j] = pp[j];
        }
    }
    for (int i = 0; i < N; i++)
        printf("%d ", p[i]);
    printf("\n");
}