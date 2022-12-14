#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#define MAXN 1000
#define SIZE (2*MAXN + 1)
using namespace std;

class TwoSAT{
    public:
    int n;
    vector < vector<int> > g, gt;
    vector<bool> used;
    vector<int> order, comp;
    void dfs1 (int v) {
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to])
                dfs1 (to);
        }
        order.push_back (v);
    }
    void dfs2 (int v, int cl) {
        comp[v] = cl;
        for (size_t i=0; i<gt[v].size(); ++i) {
            int to = gt[v][i];
            if (comp[to] == -1)
                dfs2 (to, cl);
        }
    }
    bool Satisfable(vector < int > &sol){
        sol.resize(n/2);
        sol.clear();
        for(int i = 0 ; i < n ; i++)
           if (!used[i])
                dfs1 (i);
        for (int i=0, j=0; i<n; ++i) {
            int v = order[n-i-1];
            if (comp[v] == -1) dfs2 (v, j++);
        }
        for(int i = 0 ; i < n ; i++)
            if (comp[i] == comp[i^1])
                return 0;
        for(int i = 0 ; i < n ; i+=2){
            int ans = comp[i] > comp[i^1] ? i : i^1;
            sol.push_back(ans%2);
        }
        return 1;
    }
    void init(int N){
        n = N * 2;
        used.clear(); order.clear(); comp.clear();
        g.resize(n);
        gt.resize(n);
        used.assign (n, false);
        comp.assign (n, -1);
    }
    void imply(int a , int na ,int b , int nb){
        // na :: 0 variable is false , 1 variable is true
        // pass variables 1 indexed
        a--; b--;
        a*=2 , b*=2;
        a += na , b +=nb;
        g[a].push_back(b);
        gt[b].push_back(a);
        g[b^1].push_back(a^1);
        gt[a^1].push_back(b^1);
    }
}G;


int U[1000000];
int V[1000000];
int n;
bool check(int i,int j)
{
    int a = U[i], b = V[i];
    if (a>b)swap(a,b);
    int c = U[j], d = V[j];
    if (c>d)swap(c,d);
    if (a>=d || c>=b)
        return 0;
    if ((a>=c && b<=d) || (c>=a && d<=b))
        return 0;
    return 1;
}
int main()  {
    int i, M;
    int m;
    scanf("%d %d", &n, &m);
    G.init(m);
    for(i=1; i<=m; i++)  {
        scanf("%d %d", &U[i], &V[i]);
        for (int j=1;j<i;j++)
        {
            if (check(i,j))
                G.imply(i,0,j,1),G.imply(i,1,j,0);
        }
    }

    vector<int> ret;

    bool c = G.Satisfable(ret);

    if(!c)
        printf("Impossible\n");
    else    {
        for(i=0; i<ret.size(); i++)
            printf("%s", ret[i] ? "o" : "i");
    }

    return 0;
}