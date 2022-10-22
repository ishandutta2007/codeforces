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
typedef long long LL;
using namespace std;
const int N = 100005;
const int M = 1000;

bool f[M];
int prime[M] , tot , p[M];
int n , m , q , B , a[N] , w[N] , L[N] , R[N];
vector<int> e[N];
bool vis[200];
void dfs(int x , int fa , int &&ncnt) {
    L[x] = ncnt;
    w[ncnt ++] = a[x];
    for (auto &y : e[x]) {
        if (y != fa) {
            dfs(y , x , move(ncnt));
        }
    }
    R[x] = ncnt - 1;
}
int cnt[400][M] , delta[400];

void BF(int l , int r , int v) {
    for (int j = l ; j < r ; ++ j) {
        int id = j / B;
        -- cnt[id][w[j]];
        w[j] = (w[j] + v) % m;
        ++ cnt[id][w[j]];
    }
}
void update(int i) {
    int l = i * B , r = min(l + B , n);
    for (int j = l ; j < r ; ++ j)
        w[j] = (w[j] + delta[i]) % m;
    rotate(cnt[i] , cnt[i] + delta[i] , cnt[i] + m);
    delta[i] = 0;
}
void QF(int l , int r) {
    for (int j = l ; j < r ; ++ j) {
        int id = j / B , x = (w[j] + delta[id]) % m;
        if (!f[x])
            vis[p[x]] = 1;
    }
}


int main() {
    scanf("%d%d" , &n , &m);
    f[0] = f[1] = 1;
    for (int i = 2 ; i < m ; ++ i) {
        if (f[i]) continue;
        p[i] = tot;
        prime[tot ++] = i;
        for (int j = i * i ; j < m ; j += i)
            f[j] = 1;
    }
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        a[i] %= m;
    }
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        -- x , -- y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(0 , -1 , 0);
    B = sqrt(max(tot , 1) * n);
    for (int i = 0 ; i < n ; ++ i) {
        cnt[i / B][w[i]] ++;
    }
    scanf("%d" , &q);
    for (int o = 0 ; o < q ; ++ o) {
        int i , x , v , l , r;
        scanf("%d%d" , &i , &x);
        -- x;
        l = L[x] , r = R[x];
        int ll = l / B , rr = r / B;
        if (i == 1) {
            scanf("%d" , &v);
            v %= m;
            if (ll == rr) {
                BF(l , r + 1 , v);
            } else {
                //update(ll);
                BF(l , min((ll + 1) * B , n) , v);
                for (int j = ll + 1 ; j < rr ; ++ j)
                    delta[j] = (delta[j] + v) % m;
                //update(rr);
                BF(rr * B , r + 1 , v);
            }
        } else {
            int res = 0;
            memset(vis , 0 , sizeof(vis));                
            if (ll == rr) {
                QF(l , r + 1);
            } else {
                //update(ll);
                QF(l , min((ll + 1) * B , n));
                QF(rr * B , r + 1);
                for (int i = 0 ; i < tot ; ++ i) {
                    for (int j = ll + 1 ; !vis[i] && j < rr ; ++ j) {
                        int x = (prime[i] - delta[j] + m) % m;
                        vis[i] |= !!cnt[j][x];
                    }
                }
                //update(rr);
            }
            for (int i = 0 ; i < tot ; ++ i)
                res += vis[i];
            printf("%d\n" , res);
        }
    }


    return 0;
}
/*
2 5
2 3
1 2
1
2 1
 */