#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 8005;

int s , t , pre[N] , mcnt;
struct arc {
    int x , f , c , next;
}e[N * 20];
inline void addarc(int x , int y , int z , int c) {
    e[mcnt] = (arc) {y , z , c , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc) {x , 0 , -c , pre[y]} , pre[y] = mcnt ++;
}
int d[N] , p[N];
bool f[N];
bool Bellman_Ford() {
    deque<int> Q;
    int i , x , y , z;
    for (i = 0 ; i <= t ; ++ i)
        d[i] = 1 << 30 , f[i] = 0;
    d[s] = 0 , f[s] = 1 , Q.push_back(s);
    while (!Q.empty()) {
        x = Q.front() , Q.pop_front() , f[x] = 0;
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x , z = e[i].c;
            if (e[i].f && d[y] > d[x] + z) {
                d[y] = d[x] + z , p[y] = i;
                if (!f[y]) {
                    if (Q.empty() || d[y] < d[Q.front()])
                        Q.push_front(y);
                    else
                        Q.push_back(y);
                    f[y] = 1;
                }
            }
        }
    }
    return d[t] != 1 << 30;
}
pair<int , int> MincostMaxflow() {
    int maxflow = 0 , ans = 0 , x;
    while (Bellman_Ford()) {
        int flow = 1 << 30;
        for (x = t ; x != s ; x = e[p[x] ^ 1].x)
            flow = min(flow , e[p[x]].f);
        maxflow += flow , ans += d[t] * flow;
        for (x = t ; x != s ; x = e[p[x] ^ 1].x)
            e[p[x]].f -= flow , e[p[x] ^ 1].f += flow;
    }
    return make_pair(maxflow , ans);
}
int n , m , a[85][85];

void work() {
    int i , j;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    s = n * m + 1 , t = s + 1;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            scanf("%d" , &a[i][j]);
    int num = 0;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j) {
            ++ num;
            if ((i + j) & 1) {
                addarc(s , num , 1 , 0);
                if (i > 1) addarc(num , num - m , 1 , a[i][j] != a[i - 1][j]);
                if (i < n) addarc(num , num + m , 1 , a[i][j] != a[i + 1][j]);
                if (j > 1) addarc(num , num - 1 , 1 , a[i][j] != a[i][j - 1]);
                if (j < m) addarc(num , num + 1 , 1 , a[i][j] != a[i][j + 1]); 
            } else {
                addarc(num , t , 1 , 0);
            }
        }
    cout << MincostMaxflow().second << endl;
}

int main() {
    work();
    return 0;
}