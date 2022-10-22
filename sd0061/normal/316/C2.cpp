#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 8005;

int s , t , pre[N] , mcnt;
int maxflow , ans;
struct arc {
    int x , f , c , next;
}e[N * 20];
void addarc(int x ,int y ,int z ,int c) {
    e[mcnt] = (arc){y , z , c , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc){x , 0 , -c , pre[y]} , pre[y] = mcnt ++;
}
int d[N];
bool f[N];
queue<int> q;
void Bellman_Ford() {
    int i , x , y , z;
    memset(f , 0 , sizeof(f));
    for (i = 0; i <= t ; ++ i) d[i] = 1 << 30;
    d[s] = 0 , f[s] = 1 , q.push(s);
    while (!q.empty()){
        x = q.front() , q.pop() , f[x] = 0;
        for (i = pre[x] ; ~i ; i = e[i].next){
            y = e[i].x , z = e[i].c;
            if (e[i].f && d[y] > d[x] + z){
                d[y] = d[x] + z;
                if (!f[y])
                    q.push(y) , f[y] = 1;
            }
        }
    }
    for (i = 0; i <= t ; ++ i) d[i] = d[t] - d[i];
}
int zkwpush(int x , int flow = 1 << 30) {
    if (x == t || !flow) {
        maxflow += flow , ans += d[s] * flow;
        return flow;
    }
    f[x] = 1; int now = flow;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x , u;
        if (e[i].f && !f[y] && d[y] + e[i].c == d[x] && (u = zkwpush(y , min(now , e[i].f)))) {
            e[i].f -= u , e[i ^ 1].f += u;
            now -= u; if (!now) break;
        }
    }
    return flow - now;
}
bool modify() {
    int dis = 1 << 30;
    for (int x = 0 ; x <= t ; ++ x) {
        if (!f[x]) continue;
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (e[i].f && !f[y])
                dis = min(dis , d[y] + e[i].c - d[x]);
        }
    }
    if (dis == 1 << 30) return 0;
    for (int x = 0 ; x <= t ; ++ x) if (f[x]) d[x] += dis;
    return 1;
}
pair<int , int> MincostMaxflow() {
    maxflow = 0 , ans = 0;
    Bellman_Ford();
    while (1) {
        while (1) {
            memset(f , 0 , sizeof(f));
            if (!zkwpush(s)) break;
        }
        if (!modify()) break;
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