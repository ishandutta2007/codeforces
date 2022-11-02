#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 200*1000+5;

int n;
std::vector<std::pair<int,int>> e[maxn];
std::vector<int> v[maxn];

void go(int i, int p, int x) {
    int y = 0; if (x == y) y++;
    for (auto &k : e[i]) {
        int j, ei; std::tie(j, ei) = k;
        if (j != p) {
            v[y].pb(ei);
            go(j, i, y);
            y++; if (x == y) y++;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        e[u].eb(v, i+1); e[v].eb(u, i+1);
    }
    go(0, -1, -1);
    int blah = 0;
    while (sz(v[blah])) blah++;
    printf("%d\n", blah);
    for (int i = 0; sz(v[i]); i++) {
        printf("%d ", sz(v[i]));
        for (int j = 0; j < sz(v[i]); j++) printf("%d%c", v[i][j], " \n"[j == sz(v[i])-1]);
    }
}