#include<iostream>
#include<vector>

using namespace std;

bool white[100001];
int cnt[100001];

vector <int> p[100001];
vector <int> res;

int solve(int v,int u)
{
    int l=p[v].size();

    if(white[v])cnt[v]++;

    for(int i=0;i<l;i++)
    {
        if(p[v][i]!=u)
        {
            cnt[v]+=solve(p[v][i],v);
        }
    }

    return cnt[v];
}

int main ()
{
    int n,i,x,y,t;

    cin>>n;

    for(i=0;i<n-1;i++)
    {
        cin>>x>>y>>t;
        p[x].push_back(y);
        p[y].push_back(x);

        if(t==2)
        {
            white[x]=1;
            white[y]=1;
        }
    }

    solve(1,0);

    for(i=1;i<=n;i++)
    {
        if(cnt[i]==1)res.push_back(i);
    }

    cout<<res.size()<<endl;

    t=res.size();

    for(i=0;i<t-1;i++)cout<<res[i]<<" ";

    if(t!=0)cout<<res[t-1]<<endl;

    return 0;
}