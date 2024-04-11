#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;

void add(LL& A , LL B) {
    A += B % Q;
    if (A >= Q)
        A -= Q;
}
LL f[N][2];
int n;
vector<int> e[N];

void dfs(int x) {
    for (int i = 0 ; i < (int) e[x].size() ; ++ i)
        dfs(e[x][i]);
    LL g[2] = {0 , 1};
    for (int i = 0 ; i < (int) e[x].size() ; ++ i) {
        int y = e[x][i];
        LL add0 = f[y][0] * g[0] + f[y][1] * g[1];
        LL add1 = f[y][0] * g[1] + f[y][1] * g[0];
        add(g[0] , add0) , add(g[1] , add1);
    }
    add(g[0] , g[0]) , add(g[1] , g[1]);
    LL h[2][2] = {{1 , 0} , {1 , 0}};
    for (int i = 0 ; i < (int) e[x].size() ; ++ i) {
        int y = e[x][i];
        LL tmp = h[0][1];
        add(h[0][1] , f[y][0] * h[0][0]);
        add(h[0][0] , f[y][0] * tmp);

        tmp = h[1][1];
        add(h[1][1] , f[y][1] * h[1][0]);
        add(h[1][0] , f[y][1] * tmp);
    }
    f[x][0] = (g[0] - h[1][1] + Q) % Q;
    f[x][1] = (g[1] - h[0][0] - h[0][1] + Q + Q) % Q;
}

int main()
{
    int i , x;
    scanf("%d",&n);
    for (i = 2 ; i <= n ; ++ i) {
        scanf("%d",&x);
        e[x].push_back(i);
    }
    dfs(1);
    cout << (f[1][0] + f[1][1]) % Q << endl;
    return 0;
}