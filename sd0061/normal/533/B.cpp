#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , a[N];
vector<int> e[N];
LL f[N][2][2] , res;

void dfs(int x) {
    for (auto y : e[x])
        dfs(y);
    f[x][1][1] = a[x];
    f[x][1][0] = -1LL << 60;
    f[x][0][1] = -1LL << 60;
    
    for (auto y : e[x]) {
        LL d[2][2];
        memcpy(d , f[x] , sizeof(d));
        f[x][0][0] = max(d[0][0] + f[y][0][0] , d[0][1] + max(f[y][0][1] , f[y][1][1]));
        f[x][0][1] = max(d[0][1] + f[y][0][0] , d[0][0] + max(f[y][0][1] , f[y][1][1]));
        f[x][1][0] = max(d[1][0] + f[y][0][0] , d[1][1] + max(f[y][0][1] , f[y][1][1]));
        f[x][1][1] = max(d[1][1] + f[y][0][0] , d[1][0] + max(f[y][0][1] , f[y][1][1]));
    }
    res = max(res , f[x][1][1]);
    res = max(res , f[x][0][1]);
    res = max(res , f[x][0][0]);    
}

void work() {
    scanf("%d" , &n);
    int i , x , root;
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d",&x,&a[i]);
        if (~x)
            e[x].push_back(i);
        else
            root = i;
    }
    dfs(root);
    cout << res << endl;
}

int main() {
    work();
    return 0;
}