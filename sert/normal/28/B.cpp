#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

void ret(string s) {
    cout << s;
    exit(0);
}

int n;
vector <int> es[N], r, f;
int a[N];
bool u[N];

void dfs(int v) {
    if (u[v]) return;
    u[v] = true;
    r.push_back(v);
    f.push_back(a[v]);
    for (int w: es[v])
        dfs(w);
}

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x <= i) {
            es[i].push_back(i - x);
            es[i - x].push_back(i);
        }
        if (x + i < n) {
            es[i].push_back(i + x);
            es[i + x].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (u[i]) continue;
        r.clear();
        f.clear();
        dfs(i);
        sort(r.begin(), r.end());
        sort(f.begin(), f.end());
        for (int i = 0; i < (int)r.size(); i++)
            if (r[i] != f[i]) {
                cout << "NO\n";
                return 0;
            }
    }
    cout << "YES\n";

    return 0;
}