#include <bits/stdc++.h>
using namespace std;
const int N = 2005;

int n;

struct graph {
    pair<int , int> a[N * N];
    int w[N];
    vector<int> e[N];
    vector<int> g[N];
    int dfn[N] , low[N] , bel[N] , ncnt , scnt , vis[N];
    stack<int> S;
    bitset<N> mask[N];
    void dfs(int x) {
        dfn[x] = low[x] = ++ ncnt;
        S.push(x) , vis[x] = 1;
        for (auto &y : e[x]) {
            if (!dfn[y]) {
                dfs(y);
                low[x] = min(low[x] , low[y]);
            } else if (vis[y]) {
                low[x] = min(low[x] , dfn[y]);
            }
        }
        if (low[x] == dfn[x]) {
            int i; ++ scnt;
            do {
                i = S.top();
                vis[i] = 0;
                S.pop();
                mask[scnt].set(i);
                bel[i] = scnt;
            } while (i != x);
        }
    }
    void DFS(int x) {
        if (vis[x]) return;
        vis[x] = 1;
        for (auto &y : g[x]) {
            DFS(y);
            mask[x] |= mask[y];
        }
    }
    void addedge(int x , int y) {
        e[x].push_back(y);
    }
    bool cal() {
        memset(dfn , 0 , sizeof(dfn));
        memset(vis , 0 , sizeof(vis));
        for (int i = 1 ; i <= n + n ; ++ i) {
            g[i].clear();
            mask[i].reset();
        }
        ncnt = scnt = 0;
        for (int i = 1 ; i <= n + n ; ++ i) {
            if (!dfn[i]) {
                dfs(i);
            }
        }
        for (int i = 1 ; i <= n ; ++ i) {
            if (bel[i] == bel[i + n]) {
                return 0;
            }
        }
        for (int i = 1 ; i <= n ; ++ i) {
            w[i] = (bel[i] < bel[i + n]);
        }
        for (int i = 1 ; i <= n + n ; ++ i) {
            for (auto &j : e[i]) {
                if (bel[i] == bel[j]) 
                    continue;
                int x = bel[i] , y = bel[j];
                g[x].push_back(y);
            }
        }
        for (int i = 1 ; i <= scnt ; ++ i) {
            DFS(i);
        }
        /*for (int i = 1 ; i <= n + n ; ++ i) {
            int x = bel[i];
            for (int j = 1 ; j <= n + n ; ++ j) {
                printf("%d" , (int)mask[x][j]);
            }
            puts("");
        }*/
        return 1;
    }
    bool init(int m) {
        for (int i = 0 ; i < m ; ++ i) {
            int x , y;
            scanf("%d%d" , &x , &y);
            a[i] = make_pair(x , y);
            if (x < 0 && y < 0) {
                x = -x;
                y = -y;
                e[x].push_back(y + n);
                e[y].push_back(x + n);
            } else if (x < 0 && y > 0) {
                x = -x;
                e[x].push_back(y);
                e[y + n].push_back(x + n);
            } else if (x > 0 && y < 0) {
                y = -y;
                e[x + n].push_back(y + n);
                e[y].push_back(x);
            } else {
                e[x + n].push_back(y);
                e[y + n].push_back(x);
            }
        }
        return cal();
    }
} A , B;
int m1 , m2;
int main() {
    scanf("%d%d%d" , &n , &m1 , &m2);
    bool t1 = A.init(m1);
    bool t2 = B.init(m2);
    if (!t1 && !t2) {
        puts("SIMILAR");
        return 0;
    } 
    if (!t1 || !t2) {
        if (!t1) {
            for (int i = 1 ; i <= n ; ++ i) {
                printf("%d%c" , B.w[i] , " \n"[i == n]);
            }
        } else {
            for (int i = 1 ; i <= n ; ++ i) {
                printf("%d%c" , A.w[i] , " \n"[i == n]);
            }
        }
        return 0;
    }

    for (int i = 0 ; i < m1 ; ++ i) {
        int x = -A.a[i].first , y = -A.a[i].second;
        if (x < 0) x = n - x;
        if (y < 0) y = n - y;
        /*B.addedge(x > n ? x - n : x + n , x);
        B.addedge(y > n ? y - n : y + n , y);
        if (B.cal()) {
            for (int i = 1 ; i <= n ; ++ i) {
                 printf("%d%c" , B.w[i] , " \n"[i == n]);
            }
            return 0; 
        }
        B.e[x > n ? x - n : x + n].pop_back();
        B.e[y > n ? y - n : y + n].pop_back();
        continue;*/
        int X = B.bel[x] , Y = B.bel[y];
        bitset<N> MASK = B.mask[X] | B.mask[Y];
        if (!((MASK >> n) & MASK).count()) {
            B.addedge(x > n ? x - n : x + n , x);
            B.addedge(y > n ? y - n : y + n , y);
            assert(B.cal());
            for (int i = 1 ; i <= n ; ++ i) {
                printf("%d%c" , B.w[i] , " \n"[i == n]);
            }
            return 0;
        }
    }
    for (int i = 0 ; i < m2 ; ++ i) {
        int x = -B.a[i].first , y = -B.a[i].second;
        if (x < 0) x = n - x;
        if (y < 0) y = n - y;
        /*A.addedge(x > n ? x - n : x + n , x);
        A.addedge(y > n ? y - n : y + n , y);
        if (A.cal()) {
            for (int i = 1 ; i <= n ; ++ i) {
                 printf("%d%c" , A.w[i] , " \n"[i == n]);
            }
            return 0; 
        }
        A.e[x > n ? x - n : x + n].pop_back();
        A.e[y > n ? y - n : y + n].pop_back();*/
        int X = A.bel[x] , Y = A.bel[y];
        bitset<N> MASK = A.mask[X] | A.mask[Y];
        if (!((MASK >> n) & MASK).count()) {
            A.addedge(x > n ? x - n : x + n , x);
            A.addedge(y > n ? y - n : y + n , y);
            assert(A.cal());
            for (int i = 1 ; i <= n ; ++ i) {
                printf("%d%c" , A.w[i] , " \n"[i == n]);
            }
            return 0;
        }
    }
    puts("SIMILAR");
}