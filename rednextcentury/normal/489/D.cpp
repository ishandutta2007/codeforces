#include<iostream>
# include <cstring>
#include <algorithm>
#include <stdio.h>
#include<vector>
using namespace std;
vector<int> adj1[1000000];
vector<int> adj2[1000000];
bool is[3001]={0};
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    long long ret=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i==j)
                continue;
            long long num=0;
            int k=adj1[i].size();
            for (int x=0;x<k;x++)
            {
                is[adj1[i][x]]=1;
            }
            int k2=adj2[j].size();
            for (int x=0;x<k2;x++)
            {
                if (is[adj2[j][x]]==1)
                    num++;
            }
            for (int x=0;x<k;x++)
            {
                is[adj1[i][x]]=0;
            }
            ret+=(num)*(num-1)/2;
        }
    }
    cout<<ret<<endl;
}