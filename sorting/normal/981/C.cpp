#include<iostream>
#include<vector>

using namespace std;

#define endl "\n"

vector<int> v[100001];
vector<int> endq;
int leaves=0;

void dfs(int u,int p)
{
    int i;

    if(v[u].size()==1 && p!=-1)
    {
        leaves++;
        endq.push_back(u);
    }

    for(i=0;i<v[u].size();i++)
    {
        if(v[u][i]==p)
            continue;
        dfs(v[u][i],u);
    }
}

vector<int> e;



int main ()
{
    int n,i,x,y,maxi=0,j;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(i=0;i<n-1;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(i=1;i<=n;i++)
    {
        if(v[i].size()>maxi)
        {
            maxi=v[i].size();
            x=i;
        }
    }


    dfs(x,-1);

    if(leaves!=v[x].size())
    {
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;

    cout<<v[x].size()<<endl;

    for(i=0;i<v[x].size();i++)
    {
        cout<<x<<" "<<endq[i]<<endl;
    }

    return 0;
}