#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool look(T &a, T b = true) { return (a == b ? true : (a = b, false)); }
typedef long long ll;

const int MaxN = 100005, inf = 1e9;

int N, M, f[MaxN], b[MaxN], pos[MaxN], a[MaxN];

int main()
{
    scanf("%d%d", &N, &M);
    std::fill(pos, pos+MaxN, -1);
    for (int i = 0; i < N; i++) {
        scanf("%d", &f[i]);
        if (pos[f[i]] == -1) pos[f[i]] = i;
        else pos[f[i]] = inf;
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &b[i]);
        if (pos[b[i]] == -1) {
            printf("Impossible\n");
            return 0;
        }
    }
    for (int i = 0; i < M; i++) {
        if (pos[b[i]] == inf) {
            printf("Ambiguity\n");
            return 0;
        } else a[i] = pos[b[i]];
    }
    printf("Possible\n");
    for (int i = 0; i < M; i++) printf("%d%c", a[i]+1, " \n"[i == M-1]);
}