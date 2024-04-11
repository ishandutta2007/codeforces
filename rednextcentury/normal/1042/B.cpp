#include<bits/stdc++.h>
#define ll long long
using namespace std;
int best[100000];
int cost[100000];
string h[100000];
int main()
{
    int n;
    cin>>n;
    best['A']=1e9;
    best['B']=1e9;
    best['C']=1e9;
    int ret=1e9;
    for (int i=0;i<n;i++)
    {
        cin>>cost[i]>>h[i];
        if (h[i].size()==3)ret=min(ret,cost[i]);
        for (int j=0;j<h[i].size();j++)
            best[h[i][j]]=min(best[h[i][j]],cost[i]);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            bool vis[4]={0};
            for (int x=0;x<h[i].size();x++)
                vis[h[i][x]-'A']=1;
            for (int x=0;x<h[j].size();x++)
                vis[h[j][x]-'A']=1;
            int cnt=0;
            char last='-';
            for (int x=0;x<3;x++)
            {
                if (!vis[x])
                {
                    cnt++;
                    last = char(x+'A');
                }
            }
            if (cnt==0)ret=min(ret,cost[i]+cost[j]);
            else if (cnt==1)ret=min(ret,cost[i]+cost[j]+best[last]);
        }
    }
    if(ret>1e8)ret=-1;
    cout<<ret<<endl;
}