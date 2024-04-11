#include<iostream>
#include<vector>

using namespace std;

vector<int> v[10001];
int c[10001],d[10001];

int dfs(int u,int p,int col)
{
    int i,res=0,cnt=0;

    //cout<<u<<" "<<col<<endl;

    if(col!=0)d[u]=col;

    if(d[u]!=c[u])
    {
        d[u]=c[u];
        col=c[u];
        res++;
    }
    else
    {
        for(i=0;i<v[u].size();i++)
        {
            if(v[u][i]==p)continue;
            if(c[v[u][i]]==d[u])cnt++;
        }

        if(!cnt)col=0;
        else
        {
            col=c[u];
        }
    }

    for(i=0;i<v[u].size();i++)
    {
        if(v[u][i]==p)continue;
        res+=dfs(v[u][i],u,col);
    }

    return res;
}

int main ()
{
    int n,i,x;

    cin>>n;

    for(i=1;i<n;i++)
    {
        cin>>x;
        x--;

        v[x].push_back(i);
        v[i].push_back(x);
    }

    for(i=0;i<n;i++)
        cin>>c[i];

    cout<<dfs(0,-1,0)<<endl;

    return 0;
}