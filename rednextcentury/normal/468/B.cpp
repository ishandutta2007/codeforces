#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#define MAXN 1000000
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

int a[1000000];
map<int,int> mp;
int main()  {
    int i, u, v,  M;
    // N is the number of variables and M is the number of clauses

    //freopen("input1.txt", "r", stdin);
//    N=4;
//    add_clause(-3,4);
//    add_clause(-3,-4);
//    add_clause(1,3);
//    add_clause(-1,2);
//    add_clause(2,-2);
//    add_clause(-2,1);
    int A,B;
    int n;
    scanf("%d%d%d", &n, &A,&B);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]),mp[a[i]]=i;
    G.init(n+2);
    G.imply(n+1,1,n+2,1);
    G.imply(n+2,0,n+1,0);
    G.imply(n+1,1,n+2,0);
    G.imply(n+2,1,n+1,0);
    for(i=1; i<=n; i++)
    {
        int x=A-a[i];
        int y=B-a[i];
        x=mp[x];
        y=mp[y];
        if (!x && !y)
        {
            printf("NO\n");
            return 0;
        }
        if (x)
            G.imply(i,0,x,0),G.imply(x,1,i,1);
        else
            G.imply(i,0,n+1,1),G.imply(n+1,0,i,1);
        if (y)
            G.imply(i,1,y,1),G.imply(y,0,i,0);
        else
            G.imply(i,1,n+1,1),G.imply(n+1,0,i,0);
    }



    vector<int> ret;
    bool c = G.Satisfable(ret);

    if(!c)
        printf("NO\n");
    else    {
        printf("YES\n");
        for(i=0; i<n; i++)
            printf("%d ", ret[i]);
        printf("\n");
    }

    return 0;
}