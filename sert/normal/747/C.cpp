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
const int N = (int)1e6 + 34;
const ll INF = (ll)2e9 + 34;

vector <int> v[N];
bool u[N];
int n, m, t, k, d, f, p, len, sum;

priority_queue <pair<int, int> > q;

int main() {
    init();

    scanf("%d%d", &n, &m);
    f = n;

    while (m--) {
        scanf("%d%d%d", &t, &k, &d);

        while (!q.empty() && -q.top().first <= t) {
            p = q.top().second;
            q.pop();
            for (int w: v[p]) {
                u[w] = false;
                f++;
            }
            v[p].clear();
        }

        if (f < k) {
            printf("-1\n");
            continue;
        }

        f -= k;
        sum = 0;
        for (int i = 0; i < n; i++)
            if (!u[i] && (int)v[len].size() < k) {
                v[len].push_back(i);
                u[i] = true;
                sum += i + 1;
            }
        q.push({-t - d, len++});

        printf("%d\n", sum);
    }

    return 0;
}