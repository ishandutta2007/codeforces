#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

void rip() { printf("-1\n"); exit(0); }

int K, Y, X, g[105][105];

int main() {
    scanf("%d%d%d", &K, &Y, &X);
    int o = 1, e = 2;
    for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) {
        if ((y+x)&1) { if (e <= K) { g[y][x] = e; e += 2; } }
        else if (o <= K) { g[y][x] = o; o += 2; }
    }
    if (o <= K || e <= K) {
        printf("-1\n");
    } else for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) {
        printf("%d%c", g[y][x], " \n"[x == X-1]);
    }
}