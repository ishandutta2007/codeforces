#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>
typedef long long LL;
using namespace std;
const int N = 205;
int n , m , pre[N] , mcnt , s , t;
struct arc {
    int x , f , next;
}e[N * N];

void addarc(int x ,int y ,int z) {
    e[mcnt] = (arc) {y , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc) {x , z , pre[y]} , pre[y] = mcnt ++;
}
int d[N] , cur[N] , q[N];
bool BFS() {
    memset(d , -1 , sizeof(d));
    int top = 0 , bot = -1;
    q[++ bot] = s , d[s] = 1;
    while (top != bot + 1) {
        int x = q[top ++];
        for (int i = pre[x] ; ~i ;i = e[i].next) {
            int y = e[i].x;
            if (!~d[y] && e[i].f) {
                d[y] = d[x] + 1 , q[++ bot] = y;
                if (y == t) return 1;
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
        if (d[y] == d[x] + 1 && (u = DFS(y , min(flow , e[i].f)))) {
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
int a[N] , S[N] , T[N];
struct edge {
    int x , y , w;
    bool operator < (const edge& R) const {
        return w < R.w;
    }
}E[N];

void divide(int l , int r) {
    if (l == r) return;
    random_shuffle(a + l , a + r + 1);
    for (int i = 0 ; i < mcnt ; i += 2) 
        e[i].f = e[i ^ 1].f = (e[i].f + e[i ^ 1].f) / 2;
    s = a[l] , t = a[r];
    E[m ++] = (edge) {s , t , -dinic()};
    int ns = 0 , nt = 0;
    for (int i = l ; i <= r ; ++ i)
        if (!~d[a[i]])
            T[nt ++] = a[i];
        else
            S[ns ++] = a[i];
    for (int i = 0 ; i < ns ; ++ i)
        a[l + i] = S[i];
    for (int i = 0 ; i < nt ; ++ i)
        a[l + ns + i] = T[i];
    divide(l , l + ns - 1);
    divide(l + ns , r);
}
int f[N];
vector<int> v[N];
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}

void work() {
    memset(pre , -1 , sizeof(pre));
    mcnt = 0;
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        int x , y , z;
        scanf("%d%d%d" , &x , &y , &z);
        addarc(x , y , z);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        a[i] = i;
        f[i] = i;
        v[i].clear();
        v[i].push_back(i);
    }
    m = 0;
    divide(1 , n);
    sort(E , E + m);
    int res = 0;
    for (int i = 0 ; i < m ; ++ i) {
        //printf("%d %d : %d\n" , E[i].x , E[i].y , E[i].w);
        res -= E[i].w;
        int x = getf(E[i].x) , y = getf(E[i].y);
        f[x] = y;
        v[y].insert(v[y].end() , v[x].begin() , v[x].end());
    }
    printf("%d\n" , res);
    int p = getf(1);
    for (int i = 0 ; i < v[p].size() ; ++ i)
        printf("%d%c" , v[p][i] , " \n"[i + 1 == v[p].size()]);
}

int main() {
    work();
    return 0;
}