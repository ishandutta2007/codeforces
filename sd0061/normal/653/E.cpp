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
const int N = 300005;

int n , m , K;
vector<int> e[N];
set<int> remain;
bool f[N];

int p[N] , d[N] , F[N];

priority_queue< pair<int , int> > Q;

int main() {
    scanf("%d%d%d" , &n , &m , &K);
    for (int i = 0 ; i < m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        if (x > y)
            swap(x , y);
        e[x].push_back(y);
        e[y].push_back(x);
        if (x == 1)
            F[y] = 1;
    }

    for (int i = 1 ; i <= n ; ++ i) {
        sort(e[i].begin() , e[i].end());
        remain.insert(i);
    }
    f[1] = 1 , remain.erase(1);
    for (int i = 2 ; i <= n; ++ i) {
        if (!F[i]) {
            Q.push(make_pair(-1 << 30 , i));
            d[i] = 1 << 30 , p[i] = 1;
        } else {
            p[i] = -1;
        }
    }
    while (!Q.empty()) {
        int x = Q.top().second;  Q.pop();
        if (f[x]) continue; f[x] = 1;
        remain.erase(x);
        int j = 0;
        auto it = remain.begin();
        while (it != remain.end()) {
            int y = *it;
            while (j < e[x].size() && e[x][j] < y) {
                ++ j;
            }
            if (j < e[x].size() && e[x][j] == y)
                it ++;
            else {
                d[y] = 1 , p[y] = x;
                Q.push(make_pair(-1 , y));
                remain.erase(it ++);
            }
        }
    }
    int deg = 0;
    for (int i = 2 ; i <= n ; ++ i) {
        if (!~p[i]) {
            puts("impossible");
            return 0;
        }
        deg += (p[i] == 1);
    }
    if (deg > K) {
        puts("impossible");
        return 0;
    }
    for (int i = 2 ; i <= n ; ++ i) {
        if (!F[i] && p[i] != 1)
            ++ deg;
    }
    if (deg < K) {
        puts("impossible");
        return 0;
    }

    puts("possible");
    return 0;
}