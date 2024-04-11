#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, x, y, a[N], b[N], cnt[N];
typedef pair <int, int> pii;
int unused;
vector <int> vec[N];
bool vis[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d", &n, &x, &y); y -= x;
        for (int i = 1; i <= n + 1; i ++) cnt[i] = vis[i] = 0, vec[i].clear();
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &b[i]);
            cnt[b[i]] ++;
            vec[b[i]].push_back(i);
        }
        if (x == n) {
            puts("YES");
            for (int i = 1; i <= n; i ++) printf("%d ", b[i]); puts("");
            continue;
        }
        for (int i = 1; i <= n + 1; i ++) if (!cnt[i]) {
            unused = i; break;
        }
        priority_queue <pii> pq;
        for (int i = 1; i <= n + 1; i ++) if (cnt[i]) pq.push(pii(cnt[i], i));
        for (int i = 0; i < x; i ++) {
            pii p = pq.top(); pq.pop();
            int u = p.second;
            int v = vec[u].back();
            vis[v] = 1, a[v] = u;
            vec[u].pop_back();
            cnt[u] --;
            if (cnt[u]) pq.push(pii(cnt[u], u));
        }
        pii p = pq.top();
        if (2 * p.first > 2 * (n - x) - y) {
            puts("NO"); continue;
        }
        vector <int> alive = vec[p.second];
        for (int i = 1; i <= n + 1; i ++) if (cnt[i] && i != p.second) {
            for (auto u : vec[i]) alive.push_back(u);
        }
        int sz = alive.size(), c = p.first;
        if (2 * c <= (n - x)) {
            for (int i = 0; i < sz; i ++) {
                int u = alive[i];
                if (i < y) {
                    a[u] = b[alive[(i+c)%sz]];
                }
                else {
                    a[u] = unused;
                }
            }
        }
        else {
            int r = n - x - c;
            assert(sz == n - x && 2 * r >= y);
            vector <int> tmp;
            for (int i = 0; i < sz; i ++) {
                int u = alive[i];
                if (i < c) {
                    if (i < r) tmp.push_back(u);
                }
                else tmp.push_back(u);
            }
            sz = tmp.size();
            for (int i = 0; i < y; i ++) {
                int u = tmp[i];
                a[u] = b[tmp[(i+r)%sz]];
                vis[u] = 1;
            }
            for (int i = 1; i <= n; i ++) if (!vis[i]) a[i] = unused;

        }


        puts("YES");
        for (int i = 1; i <= n; i ++) printf("%d ", a[i]); puts("");
    }

    return 0;
}