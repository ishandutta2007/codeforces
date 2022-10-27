#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int NICO = 3002;
int n, m;
int a[102], x[102], y[102], cnt[102];

int N, NP, NC, M;
struct Edge
{
    int u, v, cap;
    Edge() {}
    Edge(int u, int v, int cap): u(u), v(v), cap(cap) {}
} es[150 * 150];

int R, S, T;
vector<int> tab[109]; // 
int dis[109];
int current[109];

void addedge(int u, int v, int cap)
{
    //printf("%d %d %d\n", u, v, cap);
    tab[u].push_back(R);
    es[R++] = Edge(u, v, cap); // 
    tab[v].push_back(R);
    es[R++] = Edge(v, u, 0); // 0
    // , 2 ^ 1 == 3 ; 3 ^ 1 == 2
}
int BFS()
{
    queue<int> q;
    q.push(S);
    memset(dis, 0x3f, sizeof(dis));
    dis[S] = 0;
    while (!q.empty())
    {
        int h = q.front();
        q.pop();
        for (int i = 0; i < tab[h].size(); i++)
        {
            Edge &e = es[tab[h][i]];
            if (e.cap > 0 && dis[e.v] == 0x3f3f3f3f)
            {
                dis[e.v] = dis[h] + 1;
                q.push(e.v);
            }
        }
    }
    return dis[T] < 0x3f3f3f3f; // 
}

int dinic(int x, int maxflow)
{
    if (x == T)
        return maxflow;
    // i = current[x] 
    for (int i = current[x]; i < tab[x].size(); i++)
    {
        current[x] = i;
        Edge &e = es[tab[x][i]];
        if (dis[e.v] == dis[x] + 1 && e.cap > 0)
        {
            int flow = dinic(e.v, min(maxflow, e.cap));
            if (flow)
            {
                e.cap -= flow; // 
                es[tab[x][i] ^ 1].cap += flow; // 
                return flow;
            }
        }
    }
    return 0; //  
}

int DINIC()
{
    int ans = 0;
 
    while (BFS()) // 
    {
        int flow;
        memset(current, 0, sizeof(current)); // BFS
        while (flow = dinic(S, 0x3f3f3f3f)) // BFS
            ans += flow;
    }
    return ans;
}

set<int> prime;

void getfac(int n) {
    for(int i=2;i*i<=n;i++) {
        if(n % i == 0) {
            prime.insert(i);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n != 1) prime.insert(n);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<=m;i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    for(int i=1;i<=n;i++) {
        getfac(a[i]);
    }

    set<int>::iterator it; int ans = 0;
    for(it = prime.begin(); it != prime.end(); it ++) {

        int p = *it;
        S = n+1;
        T = n+2;
        R = 0;

        //printf("%d\n", p);

        for(int i = 1; i <= n; i++) {
            int tmp = a[i];
            int num = 0;
            while(a[i] % p == 0) {
                num ++; a[i] /= p;
            }
            cnt[i] = num;
            //printf("cnt[%d] : %d\n", i, num);
        }

        for(int i = 0; i <= n + 2; i++) {
            tab[i].clear();
        }

        for(int i = 1; i <= n; i += 2) {
            addedge(S, i, cnt[i]);
        }

        for(int i = 2; i <= n; i += 2) {
            addedge(i, T, cnt[i]);
        }

        for(int i=1;i<=m;i++) {
            if(x[i] % 2 == 0) swap(x[i], y[i]);
            addedge(x[i], y[i], min(cnt[x[i]], cnt[y[i]]));
        }

        //printf("fuck\n");

        ans += DINIC();
    }

    cout << ans << endl;
}