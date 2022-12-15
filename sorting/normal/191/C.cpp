#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> v[100001];
vector<int> w[100001];
int res[100001];
int n,l;
int up[100001][20],level[100001];
int a[100001];

int sum(int u,int parent)
{
    int i,x=a[u];

    for(i=0;i<v[u].size();i++)
    {
        if(v[u][i]==parent)
            continue;
        res[w[u][i]]=sum(v[u][i],u);
        x+=res[w[u][i]];
    }

    return x;
}

int lca(int u1,int u2)
{
    int i;

    if(level[u1]<level[u2])
        swap(u1,u2);

    while(level[u1]!=level[u2])
    {
        //cout<<u1<<" - "<<u2<<endl;
        //cout<<level[u1]<<" "<<level[u2]<<endl;
        //cout<<log2(level[u1]-level[u2])<<endl;
        u1=up[u1][(int)log2(level[u1]-level[u2])];
    }

    for(i=l;i>=0;i--)
    {
        if(up[u1][i]!=up[u2][i])
        {
            u1=up[u1][i];
            u2=up[u2][i];
        }
    }

    if(u1==u2)
        return u1;

    return up[u1][0];
}

void dfs(int u,int parent)
{
    int i;
    up[u][0]=parent;
    level[u]=level[parent]+1;
    //cout<<level[u]<<" "<<u<<endl;

    for(i=1;i<=l;i++)
        up[u][i]=up[up[u][i-1]][i-1];

    for(i=0;i<v[u].size();i++)
    {
        if(v[u][i]==parent)
            continue;

        dfs(v[u][i],u);
    }
}

void preprocessing()
{
    l=ceil(log2(n));
    dfs(1,1);
}

int main ()
{
    int i,x,y,t;

    cin>>n;

    for(i=0;i<n-1;i++)
    {
        cin>>x>>y;

        v[x].push_back(y);
        w[x].push_back(i);
        v[y].push_back(x);
        w[y].push_back(i);
    }

    preprocessing();

    int q;

    cin>>q;

    for(i=0;i<q;i++)
    {
        cin>>x>>y;

        t=lca(x,y);

        if(t==x)
        {
            a[t]--;
            a[y]++;
        }
        else
        {
            if(t==y)
            {
                a[t]--;
                a[x]++;
            }
            else
            {
                a[t]-=2;
                a[x]++;
                a[y]++;
            }
        }
    }

    sum(1,-1);

    for(i=0;i<n-2;i++)
        cout<<res[i]<<" ";
    cout<<res[i]<<endl;

    return 0;
}
/*
10
1 2
2 7
2 6
2 4
4 10
4 5
1 3
3 8
3 9
*/