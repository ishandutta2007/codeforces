#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m , q;
vector<int> operator + (const vector<int> &A , const vector<int> &B) {
    vector<int> C(A.size() + B.size());
    merge(A.begin() , A.end() , B.begin() , B.end() , C.begin());
    if (C.size() > 10)
        C.resize(10);
    return C;
}
vector<int> e[N];
vector<int> V[17][N];
int dep[N] , f[17][N];

void dfs(int x , int fa) {
    f[0][x] = fa , dep[x] = dep[fa] + 1;
    sort(V[0][x].begin() , V[0][x].end());
    if (V[0][x].size() > 10)
        V[0][x].resize(10);
    for (auto &y : e[x])
        if (y != fa)
            dfs(y , x);
}

int main() {
    scanf("%d%d%d" , &n , &m , &q);
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1 ; i <= m ; ++ i) {
        int x;
        scanf("%d" , &x);
        V[0][x].push_back(i);
    }
    dfs(1 , 0);
    for (int j = 1 ; j < 17 ; ++ j)
        for (int i = 1 ; i <= n ; ++ i) {
            int x = f[j - 1][i];
            f[j][i] = f[j - 1][x];
            V[j][i] = V[j - 1][i] + V[j - 1][x];
        }
    while (q --) {
        int x , y , k;
        scanf("%d%d%d" , &x , &y , &k);
        vector<int> res;
        if (dep[x] < dep[y])
            swap(x , y);
        for (int i = 16 ; i >= 0 ; -- i)
            if (dep[x] - dep[y] >> i & 1) {
                res = res + V[i][x];
                x = f[i][x];
            }
        if (x != y) {
            for (int i = 16 ; i >= 0 ; -- i)
                if (f[i][x] != f[i][y]) {
                    res = res + V[i][x];
                    res = res + V[i][y];
                    x = f[i][x];
                    y = f[i][y];
                }
            res = res + V[1][x] + V[0][y];
        } else
            res = res + V[0][y];
        int cnt = min((int)res.size() , k);
        printf("%d" , cnt);
        for (int i = 0 ; i < cnt ; ++ i)
            printf(" %d" , res[i]);
        puts("");
    }
    return 0;
}