#include<iostream>
#include<vector>

using namespace std;

vector<long long> v[300001];
long long used[300001];

long long dfs(long long u,long long f)
{
    if(u==f)
    {
        used[u]=2;
        return 2;
    }

    used[u]=1;

    long long p;

    for(long long i=0;i<v[u].size();i++)
        if(!used[v[u][i]])
        {
            p=dfs(v[u][i],f);
            if(p==2)
            {
                used[u]=2;
                return 2;
            }
        }
    return 1;
}

long long dfs2(long long u)
{
    used[u]=1;

    long long res=1;

    for(long long i=0;i<v[u].size();i++)
        if(!used[v[u][i]])
            res+=dfs2(v[u][i]);

    return res;
}

int main ()
{
    long long n,x,y,a,b,i,res=0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x>>y;

    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(x,y);

    for(i=1;i<=n;i++)
        if(used[i]==1)
            used[i]=0;

    res=(long long)n*(n-1)-dfs2(x)*dfs2(y);

    cout<<res<<endl;

    return 0;
}