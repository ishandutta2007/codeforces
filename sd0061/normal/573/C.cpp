#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m;
vector<int> e[N];
bool del[N];
int leg[N];
void dfs(int x , int fa) {
    if (e[x].size() <= 2) {
        del[x] = 1;
        for (auto &y : e[x]) {
            if (y != fa)
                dfs(y , x);
        }
    }
}


int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1 ; i <= n ; ++ i)
        if (e[i].size() == 1)
            dfs(i , 0);
    for (int i = 1 ; i <= n ; ++ i)
        for (auto &y : e[i])
            if (del[y])
                ++ leg[i];
    for (int i = 1 ; i <= n ; ++ i) {
        if (del[i]) continue;
        int cnt = 0;
        for (auto &y : e[i])
            if (!del[y] && (int)e[y].size() - min(2 , leg[y]) > 1)
                ++ cnt;
        if (cnt > 2) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}