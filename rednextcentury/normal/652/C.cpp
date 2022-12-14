
 #include<bits/stdc++.h>
using namespace std;
multiset<int> s;
int a[1000000];
int val[1000000];
vector<int> adj[1000000];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        val[a[i]]=i;
    }
    for (int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u=val[u];
        v=val[v];
        if (u<v)
            swap(v,u);
        adj[u].push_back(v);
    }
    int l=1;
    long long ans=0;
    for (int r=1;r<=n;r++)
    {
        for (int i=0;i<adj[r].size();i++)
            s.insert(adj[r][i]);
        while(s.size() && *(--s.end())>=l)
            l++;
        ans+=(r-l+1);
    }
    cout<<ans<<endl;
}