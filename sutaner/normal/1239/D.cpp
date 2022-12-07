#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define maxn 3000019
using namespace std;

int n, m;
struct edge{
    int next, to;
    edge(int next, int to) : next(next), to(to){}
    edge(){}
}e[maxn];
int cnt = 0, h[maxn];
void Add_Edge(int x, int y){
    e[++cnt] = edge(h[x], y);
    h[x] = cnt;
}
int t = 0;
int low[maxn], dfs[maxn], sccno[maxn];
vector<int> node[maxn];
int ct = 0;
int s[maxn];
int head = 0;
bool vis[maxn];
int Tarjan(int x){
    low[x] = dfs[x] = ++t;
    s[++head] = x;
    vis[x] = 1;
    erep(i, x){
        int op = e[i].to;
        if (sccno[op]) continue;
        else if (vis[op]) low[x] = min(low[x], low[op]);
        else low[x] = min(low[x], Tarjan(op));
    }
    if (low[x] == dfs[x]){
        ++ct;
        int _x = s[head--];
        while (_x != x){
            sccno[_x] = ct;
            node[ct].pb(_x);
            _x = s[head--];
        }
        sccno[x] = ct;
        node[ct].pb(x);
    }
    return low[x];
}

bool visans[maxn];
bool out[maxn];

void recover(){
    rep(i, 1, ct) node[i].clear(), out[i] = 0;
    cnt = t = ct = head = 0;
    rep(i, 1, (n << 1)) low[i] = dfs[i] = sccno[i] = h[i] = vis[i] = visans[i] = 0;
}

int main(){
    int T, x, y;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        rep(i, 1, m){
            scanf("%d%d", &x, &y);
            if (x != y) Add_Edge(x, y + n);
            else Add_Edge(y + n, x), Add_Edge(x, y + n);
        }
        rep(i, n + 1, (n << 1)) if (!sccno[i]) Tarjan(i);

        #ifdef DEBUG
            printf("%d\n", ct);
            rep(i, 1, (n << 1)) printf("%d ", dfs[i]); printf("\n");
            rep(i, 1, (n << 1)) printf("%d ", low[i]); printf("\n");
            rep(i, 1, (n << 1)) printf("%d ", sccno[i]); printf("\n");
        #endif

        rep(i, 1, (n << 1)){
            erep(j, i){
                int op = e[j].to;
                if (sccno[op] != sccno[i]) out[sccno[i]] = 1;
            }
        }

        if (ct == 1) printf("No\n"); 
        else {
            printf("Yes\n");
            int root = 1;
            rep(i, 1, ct) if (!out[i]) {root = i; break;} 
            int ss = node[root].size();
            sort(node[root].begin(), node[root].end());
            printf("%d %d\n", ss >> 1, n - (ss >> 1));
            srep(i, 0, ss) if (node[root][i] <= n) printf("%d ", node[root][i]), visans[node[root][i]] = 1; printf("\n");
            rep(i, 1, n) if (!visans[i]) printf("%d ", i); printf("\n");
        }
        recover();
    }
    return 0;
}