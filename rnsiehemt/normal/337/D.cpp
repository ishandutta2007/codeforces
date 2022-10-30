#include <cstdio>
#include <vector>
#include <algorithm>

const int inf = 999999999;

int N, M, D;
bool f[100005];
std::vector<int> e[100005];
std::vector<int> c[100005];
int maxd[100005];
int ans;

void root(int at, int from) {
    for (int i = 0; i < (int)e[at].size(); i++) {
        if (e[at][i] == from) continue;
        root(e[at][i], at);
        c[at].push_back(e[at][i]);
    }
}

void pre(int at) {
    maxd[at] = -inf;
    if (f[at]) maxd[at] = 0;
    for (int i = 0; i < (int)c[at].size(); i++) {
        pre(c[at][i]);
        maxd[at] = std::max(maxd[at], maxd[c[at][i]]+1);
    }
}

void calc(int at, int pd) {
    int maxcd = -inf;
    if (f[at]) {
        pd = std::max(pd, 0);
    }
    if (c[at].empty()) {
    }
    else if ((int)c[at].size() == 1) {
        calc(c[at][0], pd+1);
        maxcd = std::max(maxcd, maxd[c[at][0]]+1);
    }
    else if ((int)c[at].size() >= 2) {
        int deepc = 0;
        for (int i = 1; i < (int)c[at].size(); i++) {
            if (maxd[c[at][i]] > maxd[c[at][deepc]])
                deepc = i;
        }
        for (int i = 0; i < (int)c[at].size(); i++) {
            maxcd = std::max(maxcd, maxd[c[at][i]]+1);
            if (i != deepc) {
                calc(c[at][i], std::max(pd+1, maxd[c[at][deepc]]+2));
            }
            else {
                int otherc = deepc == 0 ? 1 : 0;
                for (int j = 0; j < (int)c[at].size(); j++) {
                    if (j == deepc) continue;
                    else if (maxd[c[at][j]] > maxd[c[at][otherc]]) otherc = j;
                }
                calc(c[at][i], std::max(pd+1, maxd[c[at][otherc]]+2));
            }
        }
    }
    
    if (std::max(pd, maxcd) <= D) ans++;
}

int main()
{
    scanf("%d%d%d", &N, &M, &D);
    for (int i = 0; i < M; i++) {
        int tmp; scanf("%d", &tmp);
        f[tmp-1] = true;
    }
    for (int i = 0; i < N-1; i++) {
        int a, b; scanf("%d%d", &a, &b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    root(0, -1);
    pre(0);
    calc(0, -inf);

    printf("%d\n", ans);
}