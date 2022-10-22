#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , c[N];
vector<int> e[N];
LL res[N];
map<int , int> cnt[N];
map<int , LL> st[N];

void dfs(int x , int fa) {
    cnt[x][c[x]] ++;
    st[x][1] = c[x];

    for (auto &y : e[x]) {
        if (y != fa) {
            dfs(y , x);
            if (cnt[x].size() < cnt[y].size()) {
                swap(cnt[x] , cnt[y]);
                swap(st[x] , st[y]);                
            }
            while (!cnt[y].empty()) {
                auto it = cnt[y].begin();

                int w = cnt[x][it -> first];
                if (w)
                    if (!(st[x][w] -= it -> first))
                        st[x].erase(w);
                cnt[x][it -> first] += it -> second;
                w += it -> second;
                st[x][w] += it -> first;
                
                cnt[y].erase(it);
            }
        }
    }

    res[x] = st[x].rbegin() -> second;
}

void work() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d" , &c[i]);
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1 , 0);
    for (int i = 1 ; i <= n ; ++ i)
        printf("%lld%c" , res[i] , " \n"[i == n]);
}

int main() {
    work();
    return 0;
}