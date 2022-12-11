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

const int N = 55;

bool cmp(const vector <pair<int, int> > &a, const vector <pair<int, int> > &b) {
    return a.size() < b.size();
}

vector <pair<int, int> > v[10000];

string a[N];
bool u[N][N];
int n, m;
bool nl;

void dfs(int x, int y, int num) {
    if (x == 0 || y == 0 || x + 1 == m || y + 1 == n) {
        if (a[y][x] == '.')
            nl = true;
        return;
    }
    if (u[y][x] || a[y][x] != '.') return;
    u[y][x] = true;

    v[num].push_back({x, y});
    dfs(x, y - 1, num);
    dfs(x, y + 1, num);
    dfs(x + 1, y, num);
    dfs(x - 1, y, num);
}

int main() {
    init();
    int num = 0, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!u[i][j]) {
                nl = false;
                dfs(j, i, num);
                if (nl) {
                    v[num].clear();
                    continue;
                }
                num++;
            }

    sort(v, v + num, cmp);
    int ko = 0;
    for (int i = 0; i < num - k; i++)
        for (auto q: v[i]) {
            a[q.second][q.first] = '*';
            ko++;
        }
    cout << ko << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << "\n";

    return 0;
}