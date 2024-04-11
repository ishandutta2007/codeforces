#include <bits/stdc++.h>

void no() {
    printf("Impossible\n");
    exit(0);
}

int N;
int a[205];
int c[205];
int E;
int e[40005];
int f[40005];
bool used[40005];
const int MAX = 20002;
bool prime[MAX+5];
std::vector<int> ee[205];
bool seen[40005];
int G;
std::vector<int> g[205];

void dfs(int at) {
    seen[at] = true;
    g[G].push_back(at);
    if (seen[ee[at][0]] && seen[ee[at][1]]) return;
    else if (seen[ee[at][0]]) dfs(ee[at][1]);
    else dfs(ee[at][0]);
}

int main()
{
    srand(time(0));

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);

    std::fill(prime+2, prime+MAX, true);
    for (int i = 2; i < MAX; i++) {
        if (prime[i]) {
            for (int k = i+i; k < MAX; k += i)
                prime[k] = false;
        }
    }

    for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
        if (prime[a[i]+a[j]]) {
            e[E] = i;
            f[E] = j;
            E++;
        }
    }

    if (E == 0) no();

    int delta = N, timer = 30000000;
    while (delta && timer--) {
        int j = rand()%E;
        if (used[j]) {
            if (c[e[j]] <= 2 && c[f[j]] <= 2) continue;
            used[j] = false;
            delta += (c[e[j]]-1 != 2) - (c[e[j]] != 2);
            c[e[j]]--;
            delta += (c[f[j]]-1 != 2) - (c[f[j]] != 2);
            c[f[j]]--;
        }
        else {
            if (c[e[j]] >= 2 && c[f[j]] >= 2) continue;
            used[j] = true;
            delta += (c[e[j]]+1 != 2) - (c[e[j]] != 2);
            c[e[j]]++;
            delta += (c[f[j]]+1 != 2) - (c[f[j]] != 2);
            c[f[j]]++;
        }
    }

    if (delta) no();

    for (int i = 0; i < E; i++) {
        if (used[i]) {
            ee[e[i]].push_back(f[i]);
            ee[f[i]].push_back(e[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (!seen[i]) {
            dfs(i);
            G++;
        }
    }

    printf("%d\n", G);
    for (int i = 0; i < G; i++) {
        printf("%d ", (int)g[i].size());
        for (int j = 0; j < (int)g[i].size(); j++) printf("%d%c", g[i][j]+1, " \n"[j == (int)g[i].size()-1]);
    }
}