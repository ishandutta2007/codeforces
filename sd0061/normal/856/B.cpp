#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;

int nodecnt;
int u[N][26] , f[N] , dep[N];
int newnode() {
    memset(u[nodecnt] , 0 , sizeof(u[nodecnt]));
    return nodecnt ++;
}
void clear() {
    nodecnt = 0;
    newnode();
}
void insert(char *str) {
    int x = 0;
    for (int i = 0 ; str[i] ; ++ i) {
        int c = str[i] - 'a';
        if (!u[x][c])
            u[x][c] = newnode();
        x = u[x][c];
        dep[x] = i + 1;
    }
}
void getFail() {
    queue<int> Q;
    for (int i = 0 ; i < 26 ; ++ i)
        if (u[0][i]) {
            f[u[0][i]] = 0;
            Q.push(u[0][i]);
        }
    while (!Q.empty()) {
        int x = Q.front() ; Q.pop();
        for (int i = 0 ; i < 26 ; ++ i) {
            int y = u[x][i];
            if (!y) {
                u[x][i] = u[f[x]][i];
            } else {
                Q.push(y);
                f[y] = u[f[x]][i];
            }
        }
    }
}


int n , F[N][2];
char str[N];
bool deg[N];
vector<int> e[N];

void dfs(int x) {
    F[x][0] = 0;
    F[x][1] = 1;
    for (auto &y : e[x]) {
        dfs(y);
        F[x][1] += F[y][0];
        F[x][0] += max(F[y][0] , F[y][1]);
    }
}

void work() {
    clear();
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        insert(str);
    }
    getFail();
    memset(deg , 0 , sizeof(deg));
    for (int i = 1 ; i < nodecnt ; ++ i) {
        e[i].clear();
    }
    for (int i = 1 ; i < nodecnt ; ++ i) {
        if (dep[f[i]] + 1 == dep[i] && f[i]) {
            deg[i] = 1;
            e[f[i]].emplace_back(i);
        }
    }
    int res = 0;
    for (int i = 1 ; i < nodecnt ; ++ i) {
        if (!deg[i]) {
            dfs(i);
            res += max(F[i][0] , F[i][1]);
        }
    }
    cout << res << endl;
}

int main() {
    int T;
    scanf("%d" , &T);
    while (T --) {
        work();
    }
}