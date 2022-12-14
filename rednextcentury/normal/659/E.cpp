    #include <bits/stdc++.h>
    #define ll long long
    #define pb push_back
    #define pii pair <int, int>
    #define fr first
    #define se second
    #define all(v) v.begin(), v.end()
    #define loop(n) for(int i = 0; i < n; i++)
    #define loopy(n) for(int j = 0; j < n; j++)
    using namespace std;
     
    const int N = 1e5 + 10;
    vector <int> adj[N];
    int cycles[N], parent[N], sz[N];
     
    int findParent(int x)
    {
        while(parent[x] != parent[parent[x]])
            parent[x] = parent[parent[x]];
        return parent[x];
    }
     
    void unionNodes(int px, int py)
    {
        if(sz[px] > sz[py])
        {
            parent[py] = parent[px];
            sz[px] += sz[py]; cycles[px]+=cycles[py];
        }
        else
        {
            parent[px] = parent[py];
            sz[py] += sz[px]; cycles[py]+=cycles[px];
        }
    }
     
     
    int main()
    {
        int n, m;
        cin>>n>>m;
     
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
     
        for(int i = 0; i < m; i++)
        {
            int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            int px = findParent(x);
            int py = findParent(y);
            if(px != py)
                unionNodes(px, py);
            else
                cycles[px]++;
        }
     
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            if(parent[i] == i)
            {
                if(!cycles[i])
                    res++;
            }
        }
        cout<<res;
     
     
        return 0;
    }