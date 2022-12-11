#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;
const ll md = (ll)1e9 + 7;

map <pair<int, ll>, int> g;
int gr[N], res;

int cnt(int n, ll msk) {
    if (g.find({n, msk}) != g.end())
        return g[{n, msk}];
    vector <bool> u(n + 1, false);
    for (ll i = 1; i <= n; i++)
        if ((msk & (1ll << i)) == 0)
            u[cnt(n - i, msk | (1ll << i))] = true;
    for (int i = 0; true; i++)
        if (!u[i])
            return g[{n, msk}] = i;
    cerr << "fail\n";
    return 0;
}

int main() {
    init();

    for (int i = 0; i <= 60; i++) {
        gr[i] = cnt(i, 0);
        //cerr << i << "\n";
    }

    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        res ^= gr[x];
    }

    printf((res ? "NO\n" : "YES\n"));

    return 0;
}