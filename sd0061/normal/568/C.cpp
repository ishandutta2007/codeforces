#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cassert>
#include <stack>
#include <set>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const int N = 405;
const int M = N * N;

char type[N] , s[N];
int L , n , m;
int X[M] , p[M] , Y[M] , q[M];

int pre[N] , mcnt;
struct edge {
    int x , next;
}e[M + M];
char sel[N][2];

void addedge(int x , int y) {
    e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
}
int ncnt , scnt , bel[N] , low[N] , dfn[N];
int f[N];
stack<int> S;
void dfs(int x) {
    int i , y;
    low[x] = dfn[x] = ++ ncnt;
    f[x] = 1 , S.push(x);
    for (i = pre[x] ; ~i ; i = e[i].next) {
        y = e[i].x;
        if (!dfn[y]) {
            dfs(y);
            low[x] = min(low[x] , low[y]);
        } else if (f[y])
            low[x] = min(low[x] , dfn[y]);
    }
    if (low[x] == dfn[x]) {
        do {
            i = S.top() , S.pop() , f[i] = 0;
            bel[i] = scnt;
        }while (i != x);
        ++ scnt;
    }
}

bool check() {
    memset(dfn , 0 , sizeof(dfn));
    ncnt = scnt = 0;
    for (int i = 0 ; i < n + n ; ++ i)
        if (!dfn[i])
            dfs(i);
    for (int i = 0 ; i < n ; ++ i)
        if (bel[i] == bel[i + n])
            return 0;
    return 1;
}

int main() {
    scanf("%s" , type);
    L = strlen(type);
    for (int i = 0 ; i < L ; ++ i)
        type[i] = (type[i] == 'C');
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        char str[10];
        scanf("%d%s" , &X[i] , str);
        p[i] = (*str == 'C');
        scanf("%d%s" , &Y[i] , str);
        q[i] = (*str == 'C');
        -- X[i] , -- Y[i];
    }
    scanf("%s" , s);
    int flag = 1;
    for (int i = 0 ; i < m ; ++ i) {
        if (type[s[X[i]] - 'a'] == p[i] && type[s[Y[i]] - 'a'] != q[i])
            flag = 0;
    }
    if (flag) {
        puts(s);
        return 0;
    }
    for (int k = n - 1 ; k >= 0 ; -- k) {
        memset(pre , -1 , sizeof(pre)) , mcnt = 0;
        for (int i = 0 ; i < n ; ++ i) {
            sel[i][0] = sel[i][1] = 0;
            if (i < k) {
                sel[i][type[s[i] - 'a']] = s[i];
            } else {
                int l = 'a' , r = 'a' + L - 1;
                if (i == k)
                    l = s[i] + 1;
                for (int j = l ; j <= r ; ++ j) {
                    if (!sel[i][type[j - 'a']])
                        sel[i][type[j - 'a']] = j;
                }
            }
            if (!sel[i][0]) addedge(i , i + n);
            if (!sel[i][1]) addedge(i + n , i);            
        }
        for (int i = 0 ; i < m ; ++ i) {
            addedge(X[i] + p[i] * n , Y[i] + q[i] * n);
            addedge(Y[i] + (!q[i]) * n , X[i] + (!p[i]) * n);            
        }
        if (check()) {
            for (int p = 0 ; p < n ; ++ p) {
                if (!sel[p][0] || !sel[p][1]) {
                    if (!sel[p][0])
                        putchar(sel[p][1]);
                    else
                        putchar(sel[p][0]);
                } else {
                    if (sel[p][0] < sel[p][1]) {
                        addedge(p + n , p);
                        if (check())
                            putchar(sel[p][0]);
                        else {
                            putchar(sel[p][1]);
                            pre[p + n] = e[-- mcnt].next;                        
                        }
                    } else {
                        addedge(p , p + n);
                        if (check())
                            putchar(sel[p][1]);
                        else {
                            putchar(sel[p][0]);
                            pre[p] = e[-- mcnt].next;
                        }
                    }
                }
            }
            puts("");
            return 0;
        }
    }
    puts("-1");
    return 0;
}