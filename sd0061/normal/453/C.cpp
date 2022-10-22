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
#define foreach(it , h) for (typeof((h).begin()) it = (h).begin() ; it != (h).end() ; ++ it)
const int N = 100005;
int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
bool u[N] , v[N] , p[N];
vector<int> res;
int F[N];
void dfs(int x , int fa) {
    F[x] = fa , v[x] = 1 , p[x] = u[x];
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!v[y]) {
            dfs(y , x);
            p[x] |= p[y];
        }
    }
}
void DFS(int x , int fa) {
    res.push_back(x) , u[x] ^= 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (F[y] == x) {
            if (!p[y])
                continue;
            DFS(y , x);
            res.push_back(x) , u[x] ^= 1;
        }
    }
    if (u[x]) {
        if (!F[x]) {
            assert(res.back() == x);
            res.pop_back(); u[x] ^= 1;
        } else {
            res.push_back(F[x]) , u[F[x]] ^= 1;
            res.push_back(x) , u[x] ^= 1;
        }
    }
}


void work() {
    int i , x , y;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
    }
    for (i = 1 , x = 0; i <= n ; ++ i) {
        scanf("%d",&u[i]);
        if (u[i])
            x = i;
    }
    if (!x) {
        puts("0");
        return;
    }
    dfs(x , 0);
    for (i = 1 ; i <= n ; ++ i)
        if (!v[i] && u[i]) {
            puts("-1");
            return;
        }
    DFS(x , 0);
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
}

int main(){
   // freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}