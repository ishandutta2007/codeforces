#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 100*1000+5;

int n, m, ans;
std::vector<int> e[maxn];
bool seen[maxn];

bool go(int i, int p) {
    seen[i] = true;
    bool allg = false;
    for (int j : e[i]) if (j != p) {
        if (seen[j]) allg = true;
        else if (go(j, i)) allg = true;
    }
    return allg;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        e[a].pb(b); e[b].pb(a);
    }
    for (int i = 0; i < n; i++) if (!seen[i]) {
        if (!go(i, -1)) ans++;
    }
    printf("%d\n", ans);
}