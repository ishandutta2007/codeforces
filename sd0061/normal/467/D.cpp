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
using namespace std;
typedef long long LL;
const int N = 500005;
int n , m , K;
pair<int , int> g[N];
int a[N];
char str[N];
map<string , int> hash;
pair<int , int> E[N];
pair<int , int> G[N] , F[N];
int deg[N] , low[N] , dfn[N];
stack<int> S;
int bel[N] , scnt , ncnt;
int pre[N] , mcnt;
struct edge {
    int x , next;
}e[N];
bool vis[N] , f[N];
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
        G[scnt] = make_pair(1 << 30 , 1 << 30);
        do {
            i = S.top() , S.pop() , f[i] = 0;
            bel[i] = scnt , G[scnt] = min(G[scnt] , g[i]);
        }while (i != x);
        ++ scnt;
    }
}

void DFS(int x) {
    if (vis[x]) return;
    F[x] = G[x]; vis[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        DFS(y);
        F[x] = min(F[x] , F[y]);
    }
}

void work() {
    int i , j;
    scanf("%d" , &n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        int cnt = 0;
        for (j = 0 ; str[j] ; ++ j) {
            str[j] = tolower(str[j]);
            cnt += (str[j] == 'r');
        }
        int len = j;
        if (hash.count(str))
            a[i] = hash[str];
        else {
            a[i] = hash[str] = m;
            g[m] = make_pair(cnt , len);
            ++ m;
        }
    }
    memset(pre , -1 , sizeof(pre));
    scanf("%d",&K);
    for (i = 0 ; i < K ; ++ i) {
        scanf("%s" , str);
        int x;
        int cnt = 0;
        for (j = 0 ; str[j] ; ++ j) {
            str[j] = tolower(str[j]);
            cnt += (str[j] == 'r');
        }
        int len = j;
        if (hash.count(str))
            x = hash[str];
        else {
            x = hash[str] = m;
            g[m] = make_pair(cnt , len);
            ++ m;
        }
        scanf("%s" , str);
        int y;
        cnt = 0;
        for (j = 0 ; str[j] ; ++ j) {
            str[j] = tolower(str[j]);
            cnt += (str[j] == 'r');
        }
        len = j;
        if (hash.count(str))
            y = hash[str];
        else {
            y = hash[str] = m;
            g[m] = make_pair(cnt , len);
            ++ m;
        }
        E[i] = make_pair(x , y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
    }
    for (i = 0 ; i < m ; ++ i)
        if (!dfn[i])
            dfs(i);
    memset(pre , -1 , sizeof(pre));
    mcnt = 0;
    for (i = 0 ; i < K ; ++ i) {
        int x = E[i].first , y = E[i].second;
        if (bel[x] != bel[y]) {
            e[mcnt] = (edge) {bel[y] , pre[bel[x]]} , pre[bel[x]] = mcnt ++;
        }
    }
    for (i = 0 ; i < scnt ; ++ i)
        DFS(i);
    LL len = 0 , cnt = 0;
    for (i = 0 ; i < n ; ++ i) {
        int x = bel[a[i]];
        len += F[x].second;
        cnt += F[x].first;
    }
    cout << cnt << ' ' << len << endl;
}

int main() {
    work();
    return 0;
}