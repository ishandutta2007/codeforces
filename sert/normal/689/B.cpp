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
const int INF = 1e9;
int n, x;
bool u[N];
int d[N];
vector <int> es[N];

int main() {
    init();

    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        es[i - 1].push_back(i);
        es[i].push_back(i - 1);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        es[i].push_back(x - 1);
        d[i] = INF;
    }
    d[0] = 0;
    priority_queue<pair<int, int> > q;
    q.push({0, 0});
    int v;
    while (!q.empty()) {
        v = q.top().second;
        q.pop();
        if (u[v]) continue;
        u[v] = true;
        for (int w: es[v]) {
            if (d[w] > d[v] + 1) {
                d[w] = d[v] + 1;
                q.push({-d[w], w});
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", d[i]);

    return 0;
}