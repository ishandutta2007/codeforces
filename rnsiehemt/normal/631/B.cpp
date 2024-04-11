#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 5005, MaxK = 100*1000+5;

int N, M, K, c[MaxK], a[MaxK], b[MaxK], g[MaxN][MaxN];
bool go[MaxK], seen[3][MaxN];

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < K; i++) scanf("%d%d%d", &c[i], &a[i], &b[i]);
    for (int i = K-1; i >= 0; i--) {
        if (!seen[c[i]][a[i]]) {
            seen[c[i]][a[i]] = true;
            go[i] = true;
        }
    }
    for (int i = 0; i < K; i++) if (go[i]) {
        if (c[i] == 1) for (int x = 1; x <= M; x++) g[a[i]][x] = b[i];
        else for (int y = 1; y <= N; y++) g[y][a[i]] = b[i];
    }
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) printf("%d%c", g[i][j], " \n"[j == M]);
}