#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int N = 222;

int n, t, a[N], b[N], d[N][N], m, c[N];
string s[N];
queue <int> q;
vector <int> res[N];

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d%d%d", a + i, b + i, a + n + i, b + n + i);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
        char buf[N];
        scanf("%s%d", buf, c + i);
        s[i] = string(buf);
    }
    for (int i = 0; i < m; ++ i) {
        q.push(i);
    }
    memset(d, 0, sizeof(d));
    for (int i = 0; !q.empty(); i = (i + 1) % (n << 1)) {
        int left = t;
        while (left > 0 && !q.empty()) {
            int cur = q.front();
            q.pop();
            int mate = (i + n) % (n << 1), 
                cost = max(1, c[cur] - (a[i] + b[mate]) - d[i % n][cur]);
            if (cost <= left) {
                left -= cost;
                res[i % n].push_back(cur);
            } else {
                d[i % n][cur] += left;            
                left = 0;
                q.push(cur);
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d", (int)res[i].size());
        if (res[i].size()) {
            for (vector <int> :: iterator iter = res[i].begin(); iter != res[i].end(); ++ iter) {
                printf(" %s", s[*iter].c_str());
            }
        }
        printf("\n");
    }
    return 0;
}