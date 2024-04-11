#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N];

int f[N] , s[N] , deg[N];
bool vis[N];
int getf(int x) {
    if (f[x] == x)
    return x;
    return f[x] = getf(f[x]);
}

void work() {
    int i , x , y;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= n ; ++ i)
    f[i] = i , s[i] = 1;
    for (i = 0 ; i < m ; ++ i) {
    scanf("%d%d",&x,&y);
    e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
    ++ deg[y];
    x = getf(x) , y = getf(y);
    if (x != y) {
        f[y] = x;
        s[x] += s[y];
    }
    }
    stack<int> S;
    for (i = 1 ; i <= n ; ++ i)
    if (!deg[i])
        S.push(i);
    while (!S.empty()) {
    x = S.top() , S.pop();
    for (i = pre[x] ; ~i ; i = e[i].next) {
        y = e[i].x;
        if (!-- deg[y]) {
        S.push(y);
        }
    }
    }
    for (i = 1 ; i <= n ; ++ i) {
    if (!deg[i]) continue;
    vis[getf(i)] = 1;
    }
    int res = 0;
    for (i = 1 ; i <= n ; ++ i)
    if (getf(i) == i)
        res += s[i] - !vis[i];
    cout << res << endl; 
}

int main() {
    work();
    return 0;
}