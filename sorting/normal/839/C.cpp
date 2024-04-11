#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

vector<int> v[100001];

bool used[100001];

double res=0;

void dfs(int u,double pr,int l)
{
    int p=v[u].size(),br=0;

    //cout<<u<<" "<<pr<<" "<<l<<endl;

    used[u]=1;

    for(int i=0;i<p;i++)
    {
        if(used[v[u][i]]==0)
        {
            br++;
        }
    }

    if(br==0)
    {
//cout<<pr<<" "<<l<<endl;
        pr=(double)pr*l;
        res=(double)res+pr;
        return;
    }

    pr=(double)pr/br;

    for(int i=0;i<p;i++)
    {
        if(used[v[u][i]]==0)
        {
            dfs(v[u][i],pr,l+1);
        }
    }

    return;
}

int main ()
{
    int n,i,x,y;

    cin>>n;

    for(i=1;i<n;i++)
    {
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1,1,0);

    printf("%0.6f\n",res);

    return 0;
}