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

const int N = (int)1e6 + 34;

vector <int> es[N];
vector <pair<int, int> > e;
int k[N];
ll sz[N];
ll ans, cur;
bool u[N];

void dfs(int v, int kmp) {
    if (u[v]) return;
    u[v] = true;
    sz[kmp]++;
    k[v] = kmp;
    for (auto w: es[v])
        dfs(w, kmp);
}

int main() {
    init();
    int n, m, v1, v2;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
        e.push_back({v1, v2});
    }

    int kmp = 0;
    for (int i = 0; i < n; i++) {
        if (!u[i]) {
            dfs(i, kmp++);
        }
    }

    for (int i = 0; i < kmp; i++) {
        ans += (sz[i] * (sz[i] - 1)) / 2;
    }

    if (ans == m)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}