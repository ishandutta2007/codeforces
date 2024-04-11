#include <bits/stdc++.h>
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
    bool Satisfiable(vector < int > &sol){
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
}twosat;
int r[1000000];
vector<int>switches[1000000];
int main()  {

    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%d",&r[i]);
    for (int i=0;i<m;i++)
    {
        int num;
        scanf("%d",&num);
        while(num--)
        {
            int op;
            scanf("%d",&op);
            op--;
            switches[op].push_back(i+1);
        }
    }
    twosat.init(m);
    for (int i=0;i<n;i++)
    {
        if (r[i]==0){
            twosat.imply(switches[i][0],0,switches[i][1],1);
            twosat.imply(switches[i][0],1,switches[i][1],0);
        }
        else{
            twosat.imply(switches[i][0],0,switches[i][1],0);
            twosat.imply(switches[i][0],1,switches[i][1],1);
        }
    }
    vector<int> sl;
    if (twosat.Satisfiable(sl))
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}