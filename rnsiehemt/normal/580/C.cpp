#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define pb push_back
#define emplace_back eb
#define mod(x) ((x)%Mod)
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

int N, M, c[MaxN], ans;
std::vector<int> e[MaxN];

void go(int i, int p, int k) {
    if (c[i]) k++;
    else k = 0;
    if (k > M) return;
    if (i && sz(e[i]) == 1) ans++;
    for (int t : e[i]) if (t != p) go(t, i, k);
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &c[i]);
    for (int i = 0; i < N-1; i++) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        e[x].pb(y);
        e[y].pb(x);
    }

    go(0, -1, 0);
    printf("%d\n", ans);
}