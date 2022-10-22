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
const int N = 200005;

int n , K , V , a[N];
vector<int> e[N];

int size[N] , cnt[N] , tot[N];

void gfs(int x , int fa) {
    size[x] = 1;
    cnt[x] = (a[x] < V);
    for (auto &y : e[x]) {
        if (y != fa) {
            gfs(y , x);
            size[x] += size[y];
            cnt[x] += cnt[y];
        }
    }
}
int down[N] , up[N];
pair<int , int> md[N][2];

void dfs(int x , int fa) {
    down[x] = up[x] = 0;
    md[x][0] = md[x][1] = make_pair(0 , 0);
    for (auto &y : e[x]) {
        if (y != fa) {
            dfs(y , x);
            if (cnt[y] == 0) {
                down[x] += down[y];                
            } else {
                pair<int , int> w(down[y] , y);
                if (w > md[x][1]) {
                    if (w > md[x][0]) {
                        md[x][1] = md[x][0];
                        md[x][0] = w;
                    } else {
                        md[x][1] = w;
                    }
                }
            }
        }
    }
    tot[x] = down[x];
    if (a[x] < V) {
        down[x] = 0;
    } else {
        down[x] += 1 + md[x][0].first;
    }
}
bool flag;
void DFS(int x , int fa) {
    if (flag) return;

    if (a[x] >= V) {
        int all = 0 , mx = 0;
        if (cnt[1] - cnt[x] == 0)
            all += up[x];
        else
            mx = max(mx , up[x]);    
        for (auto &y : e[x]) {
            if (y != fa) {
                if (cnt[y] == 0)
                    all += down[y];
                else
                    mx = max(mx , down[y]);
            }
        }
        all += 1 + mx;
        if (all >= K) {
            flag = 1;
            return;
        }
    }

    for (auto &y : e[x]) {
        if (y != fa) {
            if (a[x] < V) {
                up[y] = 0;
            } else {
                int tmp = tot[x];
                int mx = 0;
                if (cnt[y] == 0) {
                    tmp -= down[y];
                } else {
                    for (int i = 0 ; i < 2 ; ++ i)
                        if (md[x][i].second != y)
                            mx = max(mx , md[x][i].first);                    
                }                
                if (cnt[1] - cnt[x] == 0)
                    tmp += up[x];
                else
                    mx = max(mx , up[x]);
                up[y] = tmp + 1 + mx;
            }
            DFS(y , x);
        }
    }
}

bool check() {
    gfs(1 , 0);
    dfs(1 , 0);
    flag = 0;
    DFS(1 , 0);
    return flag;
}

int main() {
    scanf("%d%d" , &n , &K);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int l = 0 , r = 1000001 , m;
    while (l < r) {
        V = m = l + r + 1 >> 1;
        if (check())
            l = m;
        else
            r = m - 1;            
    }
    cout << l << endl;
    return 0;
}