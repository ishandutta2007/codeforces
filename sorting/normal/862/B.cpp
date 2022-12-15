#include<iostream>
#include<vector>

using namespace std;


vector <int> vec[100001];
int cnt;
bool b[100001];
bool used[100001];

void dfs(int v,bool boo)
{
    int i;

    used[v]=1;
    b[v]=boo;
    if(!boo)cnt++;

    for(i=0;i<vec[v].size();i++)
    {
        if(!used[vec[v][i]])dfs(vec[v][i],1-boo);
    }
}

int main ()
{
    long long n,br1,br2,i,u,v,res=0;

    cin>>n;

    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    dfs(1,0);

    for(i=1;i<=n;i++)
    {
        if(b[i])
        {
            res+=cnt-vec[i].size();
        }
    }

    cout<<res<<endl;

    return 0;
}