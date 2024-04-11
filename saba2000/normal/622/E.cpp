#include<bits/stdc++.h>
using namespace std;
int h[500009];
vector<int> v[500009];
vector<long long> V;
void dfs(int x, int d)
{
    h[x]=1;
    if(v[x].size()==1) V.push_back(d);
    for (int i=0; i < v[x].size(); i++)
    {
        if(h[v[x][i]]==0) dfs(v[x][i],d + 1);
    }
}
main()
{
    int n;
    cin >> n;
    for (int i =1; i < n; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    long long ans = 0;
    h[1] = 1;
    for (int i =0; i < v[1].size(); i++)
    {
        V.clear();
        dfs(v[1][i],1);
        sort(V.begin(),V.end());
        long long M  = -1 ;
        for (int i = 0; i < V.size(); i++)
        {
            if( V[i] <= M)
            {
                V[i] = M+1;
                M++;
            }
            else M = V[i];
        }
        ans=max(ans,M);
    }
    cout <<  ans << endl;
}