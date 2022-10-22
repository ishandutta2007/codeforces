#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;
int n , m , K , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
bool vis[N];
int deg[N] , cnt[N];
vector<int> res;
void work() {
    scanf("%d%d%d" , &n , &m , &K);
    memset(pre , -1 , sizeof(pre));
    while (K --) {
        int x;
        scanf("%d" , &x);
        vis[x] = 1;
    }
    for (int i = 0 ; i < m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
        ++ deg[x] , ++ deg[y];
    }
    priority_queue< pair<double , int> > Q;
    for (int i = 1 ; i <= n ; ++ i) {
        if (!vis[i]) {
            for (int j = pre[i] ; ~j ; j = e[j].next)
                cnt[i] += !vis[e[j].x];
            Q.push(make_pair(-1.0 * cnt[i] / deg[i] , i));
        }
    }
    int X = 0 , Y = 1 , p = -1;
    while (!Q.empty()) {
        int x = Q.top().second; Q.pop();
        if (vis[x]) continue; vis[x] = 1;
        if ((LL)X * deg[x] <= (LL)cnt[x] * Y) {
            p = res.size();
            X = cnt[x];
            Y = deg[x];
        }
        res.push_back(x);
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            -- cnt[y];
            Q.push(make_pair(-1.0 * cnt[y] / deg[y] , y));
        }
    }
    printf("%d\n" , (int)res.size() - p);
    for (int i = p ; i < res.size() ; ++ i)
        printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
    
}

int main() {
    work();    
    return 0;
}