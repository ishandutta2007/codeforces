#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 100005;

int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
} e[N << 1];
int seq[N] , ncnt , L[N] , R[N] , dep[N] , f[17][N] , Lev;

void dfs(int x , int fa) {
    f[0][x] = fa;
    seq[++ ncnt] = x;
    L[x] = ncnt;
    dep[x] = dep[fa] + 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x);
        }
    }
    R[x] = ncnt;
}

int LCA(int x , int y) {
    if (dep[x] < dep[y])
        swap(x , y);
    for (int i = Lev ; i >= 0 ; -- i)
        if (dep[x] - dep[y] >> i & 1)
            x = f[i][x];
    if (x == y) return x;
    for (int i = Lev ; i >= 0 ; -- i)
        if (f[i][x] != f[i][y]) {
            x = f[i][x];
            y = f[i][y];
        }
    return f[0][x];
}
bool isanc(int x , int y) {
    return L[x] <= L[y] && R[y] <= R[x];
}
bool cmp(int a , int b) {
    return L[a] < L[b];
}
int a[N] , K , type[N] , boom[N];
vector<int> E[N];
stack<int> S;
int F[N][2];

void DFS(int x) {
    for (auto &y : E[x]) {
        DFS(y);
    }
    if (type[x] == 1) {
        F[x][1] = 0;
        for (auto &y : E[x])
            F[x][1] = min(F[x][1] + F[y][0] , 0x3F3F3F3F);
    } else {
        LL s0 = 0 , s1 = 1; int delta = 0;
        for (auto &y : E[x]) {
            s0 += F[y][0];
            delta = min(delta , F[y][1] - F[y][0]);
            s1 += min(F[y][0] , F[y][1]);
        }
        F[x][0] = min(0x3F3F3F3FLL , min(s0 , s1));
        F[x][1] = min(0x3F3F3F3FLL , s0 + delta);
    }
    if (boom[x])
        F[x][0] = min(F[x][0] , F[x][1] + 1);
}

int main() {
    scanf("%d" , &n);
    memset(pre , -1 , sizeof(pre));
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0);
    for (int j = 1 ; 1 << j < n ; ++ j) {
        for (int i = 1 ; i <= n ; ++ i)
            f[j][i] = f[j - 1][f[j - 1][i]];
        Lev = j;
    }
    scanf("%d" , &m);

    while (m --) {
        scanf("%d" , &K);
        for (int i = 0 ; i < K ; ++ i) {
            scanf("%d" , a + i);
            type[a[i]] = 1;
        }
        sort(a , a + K , cmp);
        int num = K;
        for (int i = 1 ; i < K ; ++ i) {
            int z = LCA(a[i - 1] , a[i]);
            //printf("%d %d : %d\n" , a[i - 1]  , a[i] , z);
            if (!type[z]) {
                a[num ++] = z;
                type[z] = 2;
            }
        }
        sort(a , a + num , cmp);
        for (int i = 0 ; i < num ; ++ i) {
            int x = a[i];
            //printf("%d%c" , x , "-\n"[i + 1 == num]);
            E[x].clear();
            F[x][0] = F[x][1] = 0x3f3f3f3f;
        }
        S.push(a[0]);
        for (int i = 1 ; i < num ; ++ i) {
            while (!isanc(S.top() , a[i]))
                S.pop();
            //printf("%d <-- %d\n" , S.top() , a[i]);
            if (dep[S.top()] + 1 < dep[a[i]]) 
                boom[a[i]] = 1;
            E[S.top()].push_back(a[i]);
            S.push(a[i]);
        }
        while (!S.empty()) S.pop();        
        DFS(a[0]);
        int res = min(F[a[0]][0] , F[a[0]][1]);
        if (res >= 0x3f3f3f3f) res = -1;
        printf("%d\n" , res);
        for (int i = 0 ; i < num ; ++ i)
            type[a[i]] = boom[a[i]] = 0;
    }
    return 0;
}