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
const int N = 505;
const int Q = 1e9 + 7;

int n , m , K;
int X[N] , Y[N] , Z[N];

int pre[N] , mcnt ,s  ,t , ans;
struct arc {
    int x , f , next;
}e[N << 2];
void addarc(int x ,int y ,int z) {
     e[mcnt] = (arc) {y , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc) {x , 0 , pre[y]} , pre[y] = mcnt ++;
}
int d[N] , cur[N] , q[N];
bool BFS() {
    memset(d , -1 , sizeof(d));
    int top = 0 , bot = -1;
    q[++ bot] = t , d[t] = 1;
    while (top != bot + 1) {
        int x = q[top ++];
        for (int i = pre[x] ; ~i ;i = e[i].next) {
            int y = e[i].x;
            if (!~d[y] && e[i ^ 1].f) {
                d[y] = d[x] + 1 , q[++ bot] = y;
                if (y == s) return 1;
            }
        }
    }
    return 0;
}
int DFS(int x , int flow = 1 << 30) {
    if (ans >= K) return 0;
    if (x == t || !flow) {
        ans += flow;
        return flow;
    }
    int sum = 0 , u;
    for (int& i = cur[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (d[x] == d[y] + 1 && (u = DFS(y , min(flow , e[i].f)))) {
            e[i].f -= u , e[i ^ 1].f += u;
            sum += u , flow -= u;
            if (!flow) break;
        }
    }
    if (!sum) d[x] = -1;
    return sum;
}
int dinic() {
    ans = 0;
    while (ans < K && BFS()) {
        memcpy(cur , pre , sizeof(cur));
        DFS(s);
    }
    return ans;
}
int check(double w) {
    memset(pre , -1 , sizeof(pre));
    mcnt = 0;
    s = 1 , t = n;
    for (int i = 0 ; i < m ; ++ i) {
        addarc(X[i] , Y[i] , (int)floor(min(Z[i] / w , 1.0 * K + 1e-3)));
    }
    dinic();
    return ans;
}

int main() {

    cin >> n >> m >> K;
    double l = 0 , r = 0;
    for (int i = 0 ; i < m ; ++ i) {
        cin >> X[i] >> Y[i] >> Z[i];
        r = max(r , 1.0 * Z[i]);
    }
    for (int T = 0 ; T < 100 ; ++ T) {
        double mid = (l + r) * 0.5;
        if (check(mid) >= K)
            l = mid;
        else
            r = mid;
    }
    printf("%.12f\n" , l * K);
    return 0;
}