#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 33005;
int s , t;
struct arc {
    int x , f , next;
}e[N<<1];
int pre[205] , mcnt;
void addarc(int x ,int y ,int z) {
    e[mcnt] = (arc) {y , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc) {x , 0 , pre[y]} , pre[y] = mcnt ++;
}
int d[205] , cur[205] , q[205];
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
            e[i].f -= u ,  e[i ^ 1].f += u;
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

int n , m;
int a[105];
bool f[N];
vector< pair<int , int> > E;
int main() {
    int i , x , j , y , k , maxv = 0;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]) , maxv = max(maxv , a[i]);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d",&x,&y);
        -- x , -- y;
        if (x & 1)
            swap(x , y);
        E.push_back(make_pair(x , y));
    }
    for (i = 2 ; i * i < N ; ++ i) if (!f[i])
        for (j = i * i ; j < N ; j += i) f[j] = 1;
    s = n , t = n + 1;
    int res = 0;
    for (j = 2 ; j * j <= maxv ; ++ j) {
        if (f[j]) continue;
        memset(pre , -1 , sizeof(pre)) , mcnt = 0;
        for (i = 0 ; i < n ; ++ i) {
            x = 0;
            while (a[i] % j == 0)
                a[i] /= j , ++ x;
            if (x) {
                if (i & 1)
                    addarc(i , t , x);
                else
                    addarc(s , i , x);
            }
        }
        for (i = 0 ; i < m ; ++ i) {
            x = E[i].first;
            y = E[i].second;
            addarc(x , y , 1 << 30);
        }
        res += dinic();
    }
    for (k = 0 ; k < n ; ++ k) {
        if (a[k] == 1) continue;
        j = a[k];
        memset(pre , -1 , sizeof(pre)) , mcnt = 0;
        for (i = 0 ; i < n ; ++ i) {
            x = 0;
            while (a[i] % j == 0)
                a[i] /= j , ++ x;
            if (x) {
                if (i & 1)
                    addarc(i , t , x);
                else
                    addarc(s , i , x);
            }
        }
        for (i = 0 ; i < m ; ++ i) {
            x = E[i].first;
            y = E[i].second;
            addarc(x , y , 1 << 30);
        }
        res += dinic();
    }
    printf("%d\n" , res);
    return 0;
}