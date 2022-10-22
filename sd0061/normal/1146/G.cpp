#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
const int M = 500000;

int pre[N] , mcnt , s , t;
struct arc {
    int x , f , next;
} e[M];
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
    if (x == t || !flow) return flow;
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
    int ans = 0;
    while (BFS()) {
        memcpy(cur , pre , sizeof(cur));
        ans += DFS(s);
    }
    return ans;
}

int n , h , m;

int main() {
    cin >> n >> h >> m;
    s = n * (h + 1) + m;
    t = s + 1;
    memset(pre , -1 , sizeof(pre));

    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        int offset = i * (h + 1);
        res += h * h;
        for (int j = 1 ; j <= h ; ++ j) {
            addarc(s, offset + j , j + j - 1);
            addarc(offset + j , offset + j - 1, 1 << 30);
        }
    }
    for (int i = 0 ; i < m ; ++ i) {
        int l , r , hh, c;
        cin >> l >> r >> hh >> c;
        addarc(n * (h + 1) + i , t , c);
        for (int j = l - 1 ; j <= r - 1 && hh < h ; ++ j) {
            addarc(j * (h + 1) + hh + 1, n * (h + 1) + i, 1 << 30);
        }
    }
    cout << res - dinic() << endl;
}