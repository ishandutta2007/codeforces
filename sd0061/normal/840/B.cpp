#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n , m , pre[N] , mcnt , d[N] , g[N];
struct edge {
    int x , next;
} e[N << 1];
bool tree[N];
bool vis[N];
bool p[N];
vector< pair<int , int> > E;
void dfs(int x , int fa) {
    vis[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!vis[y]) {
            g[y] = i;
            tree[i >> 1] = 1;
            dfs(y , x);
        }
    }
}

int gao(int x ,  int y) {
    //cout << x << ' ' << y << endl;
    p[x] ^= 1 , p[y] ^= 1;
}

void DFS(int x , int fa = 0) {
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (tree[i >> 1] && y != fa) {
            DFS(y , x);
            p[x] ^= p[y];
        }
    }
}

int main() {
    scanf("%d%d" , &n , &m);
    int node = -1;
    vector<int> V;
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &d[i]);
        if (d[i] == -1) {
            node = i;
        } else if (d[i] == 1) {
            V.push_back(i);
        }
    }
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (int i = 1 ; i <= m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0);

    if (~node) {
        for (auto &x : V) {
            gao(x , node);
        }
    } else if (V.size() % 2 == 0) {
        for (int i = 0 ; i < V.size() ; i += 2) {
            gao(V[i] , V[i + 1]);
        }
    } else {
        puts("-1");
        return 0;
    }
    DFS(1);
    vector<int> res;
    for (int i = 2 ; i <= n ; ++ i) {
        if (p[i]) {
            res.push_back(g[i] >> 1);
        }
    }
    printf("%d\n" , res.size());
    for (auto &x : res) {
        printf("%d " , x + 1);
    } puts("");
}