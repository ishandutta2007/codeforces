#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , a[N];
vector<int> e[N];
LL res;
LL dep[N] , down[N] , up[N] , h[N];
pair<LL , int> mdn[N][3] , mdp[N][4];

void update(pair<LL , int>* sel , int m , pair<LL , int> w) {
    int x = m;
    while (x && w > sel[x - 1]) {
        sel[x] = sel[x - 1];
        -- x;
    }
    sel[x] = w;
}

void dfs(int x , int fa) {
    for (auto &y : e[x]) {
        if (y != fa) {
            dfs(y , x);
            update(mdp[x] , 3 , make_pair(dep[y] , y));
            update(mdn[x] , 2 , make_pair(down[y] , y));
        }
    }
    dep[x] = mdp[x][0].first + a[x];
    down[x] = max(mdn[x][0].first , mdp[x][0].first + mdp[x][1].first + a[x]);
}

void DFS(int x , int fa) {  
    res = max(res , up[x] + down[x]);
    for (auto &y : e[x]) {
        if (y != fa) {
            up[y] = max(up[y] , up[x]);
            for (int i = 0 ; i < 2 ; ++ i)
                if (mdn[x][i].second != y)
                    up[y] = max(up[y] , mdn[x][i].first);
            h[y] = h[x] + a[x];
            for (int i = 0 ; i < 2 ; ++ i)
                if (mdp[x][i].second != y) {
                    h[y] = max(h[y] , a[x] + mdp[x][i].first);
                    up[y] = max(up[y] , a[x] + h[x] + mdp[x][i].first);
                }
            for (int i = 0 ; i < 3 ; ++ i)
                for (int j = i + 1 ; j < 3 ; ++ j) {
                    if (mdp[x][i].second == y || mdp[x][j].second == y)
                        continue;
                    up[y] = max(up[y] , a[x] + mdp[x][i].first + mdp[x][j].first);
                }
            DFS(y , x);
        }
    } 
}



int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1 , 0);
    DFS(1 , 0);
    cout << res << endl;
    return 0;
}