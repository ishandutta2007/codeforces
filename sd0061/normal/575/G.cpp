#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m;
vector< pair<int , int> > e[N];
int ds[N];
int dis[N] , pre[N] , w[N] , vis[N];
struct opt {
    int x , w , p;
};

void BFS(int x , int *d) {
    for (int i = 0 ; i < n ; ++ i)
        d[i] = 0x3f3f3f3f;
    queue<int> Q;
    Q.push(x) , d[x] = 0;
    while (!Q.empty()) {
        x = Q.front() , Q.pop();
        for (auto &it : e[x]) {
            int y = it.second;
            if (d[y] > n) {
                d[y] = d[x] + 1;
                Q.push(y);
            }
        }
    }
}

void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        int x , y , z;
        scanf("%d%d%d" , &x , &y , &z);
        e[x].push_back({z , y});
        e[y].push_back({z , x});
    }
    queue<int> Q;
    vector<int> cur , nxt;

    for (int i = 0 ; i < n ; ++ i)
        dis[i] = 0x3f3f3f3f;
    Q.push(n - 1) , dis[n - 1] = 0 , pre[n - 1] = -1;
    while (!Q.empty()) {
        int x = Q.front() ; Q.pop();
        cur.push_back(x);
        vis[x] = 1;
        for (auto &it : e[x]) {
            int y = it.second;
            if (!it.first && dis[y] > n) {
                pre[y] = x;
                dis[y] = dis[x] + 1;
                Q.push(y);
            }
        }
    }
    BFS(0 , ds);

    int len = 0x3f3f3f3f;
    for (auto &it : cur) {
        len = min(len , ds[it]);
        dis[it] = 0;
    }
    while (1) {
        nxt.clear();
        vector< opt > V;
        int mn = 1 << 30;
        for (auto &x : cur) {
            if (x == 0) {
                vector<int> res , ans;
                while (1) {
                    res.push_back(x);
                    if (pre[x] == -1)
                        break;
                    ans.push_back(w[x]);
                    x = pre[x];
                }
                reverse(ans.begin() , ans.end());
                bool flag = 0;
                for (auto &it : ans) {
                    if (flag || it)
                        printf("%d" , it);
                    flag |= !!it;
                }
                if (!flag)
                    putchar('0');
                puts("");
                printf("%d\n" , (int)res.size());
                for (auto &it : res)
                    printf("%d " , it);
                return;
            }
            for (auto &it : e[x]) {
                int y = it.second;
                if (!vis[y] && dis[x] + 1 + ds[y] == len) {
                    V.push_back({y , it.first , x});
                    mn = min(mn , it.first);
                }
            }
        }
        for (auto& it : V) {
            int x = it.x;
            if (it.w == mn && !vis[x]) {
                vis[x] = 1;
                w[x] = it.w;
                pre[x] = it.p;
                dis[x] = dis[it.p] + 1;
                nxt.push_back(x);
            }
        }
        swap(cur , nxt);
    }
}
int main() {
    work();
    return 0;
}