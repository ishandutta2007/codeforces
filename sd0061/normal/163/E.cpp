#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 1000005;
int n , K;
char str[M];
int u[M][26] , f[M] , cnt;
int pos[M];
queue<int> Q;
bool exist[N];
int pre[M] , mcnt;
struct edge {
    int x , next;
}e[M];
int ncnt , L[M] , R[M] , c[M];

void dfs(int x) {
    L[x] = ++ ncnt;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        dfs(e[i].x);
    R[x] = ncnt;
}

void work() {
    int i , j , x , y;
    scanf("%d%d",&K,&n);
    cnt = 1;
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%s" , str);
        x = 0;
        for (j = 0 ; str[j] ; ++ j) {
            int c = str[j] - 'a';
            if (!u[x][c])
                u[x][c] = cnt ++;
            x = u[x][c];
        }
        pos[i] = x;
    }
    for (i = 0 ; i < 26 ; ++ i) {
        if (u[0][i]) {
            Q.push(u[0][i]);
            f[u[0][i]] = 0;
        }
    }
    while (!Q.empty()) {
        x = Q.front() , Q.pop();
        for (i = 0 ; i < 26 ; ++ i) {
            if (!u[x][i]) {
                u[x][i] = u[f[x]][i];
            } else {
                y = u[x][i];
                j = f[x] , Q.push(y);
                while (j && !u[j][i])
                    j = f[j];
                f[y] = u[j][i];
            }
        }
    }
    memset(pre , -1 , cnt << 2);
    for (i = 1 ; i < cnt ; ++ i) {
        x = f[i];
        e[mcnt] = (edge) {i , pre[x]} , pre[x] = mcnt ++;
    }
    dfs(0);
    for (i = 1 ; i <= n ; ++ i) {
        x = pos[i] , exist[i] = 1;
        for (j = L[x] ; j <= cnt ; j += j & -j)
            ++ c[j];
        for (j = R[x] + 1 ; j <= cnt ; j += j & -j)
            -- c[j];
    }
    while (K --) {
        scanf("%s" , str);
        if (*str == '+') {
            sscanf(str + 1 , "%d" , &x);
            if (exist[x])
                continue;
            exist[x] = 1 , x = pos[x];
            for (j = L[x] ; j <= cnt ; j += j & -j)
                ++ c[j];
            for (j = R[x] + 1 ; j <= cnt ; j += j & -j)
                -- c[j];
        }
        if (*str == '-') {
            sscanf(str + 1 , "%d" , &x);
            if (!exist[x])
                continue;
            exist[x] = 0 , x = pos[x];
            for (j = L[x] ; j <= cnt ; j += j & -j)
                -- c[j];
            for (j = R[x] + 1 ; j <= cnt ; j += j & -j)
                ++ c[j];
        }
        if (*str == '?') {
            LL res = 0;
            x = 0;
            for (i = 1 ; str[i] ; ++ i) {
                x = u[x][str[i] - 'a'];
                for (j = L[x] ; j > 0 ; j -= j & -j)
                    res += c[j];
            }
            printf("%I64d\n" , res);
        }

    }
}

int main() {
    work();
    return 0;
}