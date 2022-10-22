#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n , m;
vector<int> e[N];
int a[N] , f[N];
vector<int> res;

void dfs(int x) {
    for (auto &y : e[x]) {
        dfs(y);
        if (a[y] && a[y] != a[x]) {
            puts("-1");
            exit(0);
        }
    }
    if (a[x] == x) {
        res.push_back(x);
        a[x] = 0;
    }
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        f[y] = x;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (!f[i]) {
            dfs(i);
        }
    }
    printf("%d\n" , (int) res.size());
    for (auto &it : res) {
        printf("%d\n" , it);
    }
}