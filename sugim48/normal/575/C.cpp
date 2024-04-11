#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<unordered_map>
//#include<quadmath.h>
using namespace std;
#define inf 1000000000
int n;
int ar[184757];
int IND[184757];
int sum[184757];
int siz = 0;
struct Edge
{
    int b, c, u, f, back;
};

class MCMF
{
private:

    int s, t, n;
    vector<Edge> g[500];

public:

    void init(int _s, int _t, int _n)
    {
        s = _s;
        t = _t;
        n = _n;
    }
    void all_er(){
        for (int i = 0; i < 500; i++){
            g[i].clear();
        }
    }
    void addEdge(int a, int b, int c, int u)
    {
        Edge e1 = { b, c, u, 0, g[b].size() };
        Edge e2 = { a, -c, 0, 0, g[a].size() };
        g[a].push_back(e1);
        g[b].push_back(e2);
    }

    int minCostMaxFlow()
    {
        int flow = 0;
        int cost = 0;
        int *state = new int[n];
        int *from = new int[n];
        int *from_edge = new int[n];
        int *d = new int[n];
        int *q = new int[n];
        int qh, qt;
        qh = 0, qt = 0;
        while (true)
        {
            for (int i = 0; i < n; i++) state[i] = 2, d[i] = inf;
            fill(from, from + n, -1);
            state[s] = 1;
            q[qh++] = s;
            d[s] = 0;
            while (qh != qt)
            {
                int v = q[qt++];
                qt %= n;
                state[v] = 0;
                for (int i = 0; i < g[v].size(); i++) if (g[v][i].f < g[v][i].u && d[g[v][i].b] > d[v] + g[v][i].c)
                {
                    int to = g[v][i].b;
                    d[to] = d[v] + g[v][i].c;
                    from[to] = v;
                    from_edge[to] = i;
                    if (state[to] == 1) continue;
                    if (!state[to])
                    {
                        qt--;
                        if (qt == -1) qt = n - 1;
                        q[qt] = to;
                        state[to] = 1;
                    }
                    else
                    {
                        state[to] = 1;
                        q[qh++] = to;
                        qh %= n;
                    }
                }
            }
            if (d[t] == inf) break;
            int it = t;
            int addflow = inf;
            while (it != s)
            {
                addflow = min(addflow, g[from[it]][from_edge[it]].u - g[from[it]][from_edge[it]].f);
                it = from[it];
            }
            it = t;
            while (it != s)
            {
                g[from[it]][from_edge[it]].f += addflow;
                g[it][g[from[it]][from_edge[it]].back].f -= addflow;
                cost += g[from[it]][from_edge[it]].c * addflow;
                it = from[it];
            }
            flow += addflow;
        }
        delete state;
        delete from;
        delete from_edge;
        delete d;
        delete q;
        return cost;
    }
};
MCMF M;
int FR[20][20];
int ST[20][20];
int FR_MAX[20];
int ST_MAX[20];
bool cmp(int &a, int &b){
    return sum[a] > sum[b];
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &FR[i][j]);
            FR_MAX[i] = max(FR_MAX[i], FR[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &ST[i][j]);
            ST_MAX[i] = max(ST_MAX[i], ST[i][j]);
        }
    }
    for (int i = 0; i < (1 << n); i++){
        int countt = 0;
        int summ = 0;
        for (int j = 0; j <n; j++){
            if ((i >> j) & 1){
                countt++;
                summ += FR_MAX[j];
            }
            else{
                summ += ST_MAX[j];
            }
        }
        if (countt == n / 2){
            sum[siz] = summ;
            ar[siz] = i;
            IND[siz] = siz;
            siz++;
        }
    }
    sort(IND, IND + siz,cmp);
    int ind = 0;
    int hal = n / 2;
    int val;
    int ans = 0;
    while (ind<siz&&clock() / (double)(CLOCKS_PER_SEC) < 1.9){
        M.all_er();
        M.init(0, 488, 500);
        val = ar[IND[ind]];
        for (int i = 0; i < n; i++){
            M.addEdge(0, i + 1, 0, 1);
        }
        for (int i = 0; i < n; i++){
            if ((val >> i) & 1){
                for (int j = 0; j < n; j++){
                    M.addEdge(i + 1, n + 1 + j, -FR[i][j], 1);
                }
            }
            else{
                for (int j = 0; j < n; j++){
                    M.addEdge(i + 1, n + 1 + j, -ST[i][j], 1);
                }
            }
        }
        for (int i = 0; i < n; i++){
            M.addEdge(i + n + 1, 488, 0, 1);
        }
        ans = min(ans, M.minCostMaxFlow());
        ind++;
    }
    cout << abs(ans) << endl;
    return 0;
}