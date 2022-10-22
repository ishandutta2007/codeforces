#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 300005;
const int M = 300005;
int n , m;
struct edge {
    int x , y , w;
    bool operator < (const edge& R) const {
        return w < R.w;
    }
}e[N];
int F[N] , G[N];

void work() {
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
    }
    sort(e , e + m);
    int res = 0;
    stack<int> S;
    for (i = 0 ; i < m ; ++ i) {
        x = e[i].x , y = e[i].y;
        F[i] = G[x] + 1;
        S.push(i);
        res = max(res , F[i]);
        if (e[i].w != e[i + 1].w) {
            while (!S.empty()) {
                j = S.top() , y = e[j].y , S.pop();
                G[y] = max(G[y] , F[j]);
            }
        }
    }
    cout << res << endl;

}

int main() {
    work();
    return 0;
}