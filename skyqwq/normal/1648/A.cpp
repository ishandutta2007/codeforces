// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, m;

vector<int> x[N], y[N];

LL ans;

void inline work(vector<int> a) {
    sort(a.begin(), a.end());
    LL s = 0, c = 0;
    for (int v: a) {
        ans += v * c - s;
        s += v, c++;
    }
}

int main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c; read(c);
            x[c].pb(i);
            y[c].pb(j);
        }
    }
    for (int i = 1; i < N; i++) {
        if (y[i].size()) work(y[i]);
        if (x[i].size()) work(x[i]);
    }
    printf("%lld\n", ans);
    return 0;
}