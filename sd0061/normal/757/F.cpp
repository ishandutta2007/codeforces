#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n , m , s;
vector< pair<int , int> > E[N];
long long d[N];

struct edge {
    int x , next;
} e[N << 5];
int mcnt;
int pre[N] , bre[N] , tree[N];
int mstamp , mvis[N];
int *prec, *succ;
vector<int> mord;
vector<int> buf[N];
int buf2[N];
int num[N] , fs[N], mins[N] , fa[N] , dom[N], sem[N];;
void dfs(int u) {
    mvis[u] = mstamp;
    num[u] = mord.size();
    mord.push_back(u);
    for (int i = succ[u] ; ~i ; i = e[i].next) {
        int v = e[i].x;
        if (mvis[v] != mstamp) {
            fa[v] = u;
            dfs(v);
        }
    }
}
int find(int u) {
    if (u != fs[u]) {
        int v = fs[u];
        fs[u] = find(fs[u]);
        if (mins[v] != -1 && num[sem[mins[v]]] < num[sem[mins[u]]]) {
            mins[u] = mins[v];
        }
    }
    return fs[u];
}
void merge(int u, int v) {
    fs[u] = v;
}
void mark(int source) {
    mord.clear();
    ++mstamp;
    dfs(source);
    for (int i = 0; i < (int)mord.size(); ++i) {
        int u = mord[i];
        fs[u] = u;
        mins[u] = -1;
        buf2[u] = -1;
    }
    for (int i = (int)mord.size() - 1; i > 0; --i) {
        int u = mord[i], p = fa[u];
        sem[u] = p;
        for (int j = prec[u]; ~j ; j = e[j].next) {
            int v = e[j].x;
            if (mvis[v] != mstamp)
                continue;
            if (num[v] > num[u]) {
                find(v);
                v = sem[mins[v]];
            }
            if (num[v] < num[sem[u]]) {
                sem[u] = v;
            }
        }
        buf[sem[u]].push_back(u);
        mins[u] = u;
        merge(u, p);
        while (buf[p].size()) {
            int v = buf[p].back();
            buf[p].pop_back();
            find(v);
            if (sem[v] == sem[mins[v]]) {
                dom[v] = sem[v];
            } else {
                buf2[v] = mins[v];
            }
        }
    }
    dom[mord[0]] = mord[0];
    for (int i = 0; i < (int)mord.size(); ++i) {
        int u = mord[i];
        if (~buf2[u]) {
            dom[u] = dom[buf2[u]];
        }
        if (u != source) {
            //printf("%d dom %d\n" , dom[u] , u);
            e[mcnt] = (edge) {u , tree[dom[u]]};
            tree[dom[u]] = mcnt ++;
        }
    }
}
int L[N] , R[N];

void dfs(int x , int &&ncnt) {
    L[x] = ++ ncnt;
    for (int i = tree[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        dfs(y , move(ncnt));
    }
    R[x] = ncnt;
}


int main() {
    prec = bre, succ = pre;
    scanf("%d%d%d" , &n , &m , &s);
    for (int i = 1 ; i <= m ; ++ i) {
        int x , y , z;
        scanf("%d%d%d" , &x , &y , &z);
        E[x].push_back({y , z});
        E[y].push_back({x , z});
    }
    priority_queue< pair<long long, int> > Q;
    memset(d , 0x3f , sizeof(d));
    d[s] = 0; Q.push({-d[s] , s});

    long long inf = d[0];
    while (!Q.empty()) {
        int x = Q.top().second; long long w = -Q.top().first; Q.pop();
        if (w > d[x]) continue;
        for (auto &it : E[x]) {
            int y = it.first;
            if (w + it.second < d[y]) {
                d[y] = w + it.second;
                Q.push({-d[y] , y});
            }
        }
    }
    memset(pre , -1 , sizeof(pre));
    memset(tree , -1 , sizeof(tree));
    memset(bre , -1 , sizeof(bre));
    for (int i = 1 ; i <= n ; ++ i) {
        if (d[i] == inf) continue;
        int x = i;
        for (auto &it : E[x]) {
            int y = it.first;
            if (d[y] == inf) continue;
            if (d[x] + it.second == d[y]) {
                //cout << x << ' ' << y << endl;
                e[mcnt] = {y - 1 , pre[x - 1]} , pre[x - 1] = mcnt ++;
                e[mcnt] = {x - 1 , bre[y - 1]} , bre[y - 1] = mcnt ++;
            }
        }
    }
    mark(-- s);
    dfs(s , 0);
    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        if (d[i + 1] == inf) continue;
        if (i != s) {
            res = max(res , R[i] - L[i] + 1);
        }
    }
    cout << res << endl;
}