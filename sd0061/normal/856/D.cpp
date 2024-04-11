#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;
int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
vector< tuple<int , int , int> > L[N];
int size[N] , heavy[N] , tid[N] , Top[N] , ncnt , dep[N] , Fa[N];
int b[N] , c[N] , res;


void FindHE(int x , int fa , int Dep) {
    heavy[x] = 0 , size[x] = 1 , dep[x] = Dep , Fa[x] = fa;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != fa)
        {
            int y = e[i].x;
            FindHE(y , x , Dep + 1);
            size[x] += size[y];
            if (!heavy[x] || size[y] > size[heavy[x]])
                heavy[x] = y;
        }
}
void ConnectHE(int x , int anc) {
    tid[x] = ++ ncnt , Top[x] = anc;
    if (heavy[x])
        ConnectHE(heavy[x] , anc);
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != Fa[x] && e[i].x != heavy[x])
            ConnectHE(e[i].x , e[i].x);
}
int LCA(int x , int y) {
    while (Top[x] != Top[y]) {
        if (dep[Top[x]] < dep[Top[y]])
            swap(x , y);
        x = Fa[Top[x]];
    }
    if (dep[x] > dep[y]) swap(x , y);
    return x;
}

inline void add(int A[] , int x , int w) {
    while (x <= n) {
        A[x] += w;
        x += x & -x;
    }
}
inline int get(int A[] , int x) {
    int sum = 0;
    while (x > 0) {
        sum += A[x];
        x -= x & -x;
    }
    return sum;
}

int query(int x , int y) {
    int ans = 0;
    while (Top[x] != Top[y]) {
        if (dep[Top[x]] < dep[Top[y]])
            swap(x , y);
        ans += get(b , tid[x]) - get(b , tid[Top[x]] - 1);
        ans -= get(c , tid[x]) - get(c , tid[Top[x]] - 1);
        x = Fa[Top[x]];
    }
    if (dep[x] > dep[y]) swap(x , y);
    ans += get(b , tid[y]) - get(b , tid[x] - 1);
    ans -= get(c , tid[y]) - get(c , tid[x] - 1);
    return ans;
}
void dfs(int x) {
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (Fa[x] != y)
            dfs(y);
    }
    int Fx = get(b , tid[x]) - get(b , tid[x] - 1);
    for (int i = 0 ; i < L[x].size() ; ++ i) {
        int y = get<0>(L[x][i]);
        int z = get<1>(L[x][i]);
        Fx = max(Fx , query(y , z) + get<2>(L[x][i]));
    }
    //cout << x << ' ' << Fx << endl;
    res = max(res , Fx);
    if (Fa[x])
        add(b , tid[Fa[x]] , Fx);
    add(c , tid[x] , Fx);
}

void work() {
    scanf("%d%d" , &n , &m);
    memset(pre , -1 , (n + 1) << 2);
    mcnt = 0;
    for (int i = 2 ; i <= n ; ++ i) {
        int x = i , y;
        scanf("%d", &y);
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
    }
    // cout << 233 << endl;
    for (int i = 1 ; i <= n ; ++ i)
        L[i].resize(0);
    ncnt = 0;
    FindHE(1 , 0 , 0);
    ConnectHE(1 , 1);
    while (m --) {
        int x , y , z;
        scanf("%d%d%d", &x, &y ,&z);
        L[LCA(x , y)].push_back(make_tuple(x , y , z));
    }
    //cout << 233 << endl;
    res = 0;
    memset(b , 0 , sizeof(b));
    memset(c , 0 , sizeof(c));
    dfs(1);
    printf("%d\n" , res);
}


int main() {
    int T;
    T = 1;
    //scanf("%d" , &T);
    while (T --) {
        work();
    }
}