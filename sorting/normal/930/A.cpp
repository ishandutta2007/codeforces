#include<iostream>
#include<vector>

using namespace std;

vector<int> v[100001];
int w[100002];
void dfs(int u,int time,int parent)
{
    w[time]++;

    for(int i=0;i<v[u].size();i++)
    {
        if(v[u][i]==parent)continue;
        dfs(v[u][i],time+1,u);
    }
}

int main ()
{
    int n,i,x,res=0;

    cin>>n;

    for(i=2;i<=n;i++)
    {
        cin>>x;

        v[x].push_back(i);
        v[i].push_back(x);
    }

    dfs(1,0,-1);

    for(i=0;i<=n;i++)
    {
        if(w[i]&1)
        {
            res++;
        }
    }

    cout<<res<<endl;

    return 0;
}