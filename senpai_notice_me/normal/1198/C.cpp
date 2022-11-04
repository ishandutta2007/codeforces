#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 5e5 + 5;

int n, m;
vector<int> edges;
set<int> vertices;

int main() {
    int case_cnt; scanf("%d", &case_cnt);
    for (int kase = 1; kase <= case_cnt; ++kase) {
        edges.clear();
        vertices.clear();
        
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (!vertices.count(u) && !vertices.count(v)) {
                edges.push_back(i);
                vertices.insert(u);
                vertices.insert(v);
            }
        }
        
        if ((int) edges.size() >= n) {
            puts("Matching");
            for (int i = 0; i < n; ++i) {
                printf("%d%c", edges[i], " \n"[i == n - 1]);
            }
        } else {
            puts("IndSet");
            int cnt = 0;
            for (int i = 1; cnt < n && i <= n * 3; ++i) if (!vertices.count(i)) {
                printf("%d%c", i, " \n"[++cnt == n]);
            }
        }
    }
    
    return 0;
}