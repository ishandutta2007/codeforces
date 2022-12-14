#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
vector<int> bian[200010];
int mn[200010],mx[200010],sz[200010],v[200010],d[200010];
void dfs(int i)
{
    v[i]=1;
    int sdz=bian[i].size(),a=inf,b=0,c=0;
    for(int j=0;j<sdz;j++)
        if(!v[bian[i][j]])
        {
            d[bian[i][j]]=d[i]+1;
            dfs(bian[i][j]);
            if(d[i]%2)
            {
                a=min(a,mn[bian[i][j]]);
                b=b-1+mx[bian[i][j]];
            }
            else
            {
                a=min(a,sz[bian[i][j]]+1-mx[bian[i][j]]);
                b=b+sz[bian[i][j]]-mn[bian[i][j]];
            }
            c+=sz[bian[i][j]];
        }
    if(c==0)
    {
        sz[i]=mn[i]=mx[i]=1;
        return;
    }
    sz[i]=c;
    if(d[i]%2)
    {
        mn[i]=a;
        mx[i]=b+1;
    }
    else
    {
        mn[i]=c-b;
        mx[i]=c-a+1;
    }
}
int main()
{
    int n,t1,t2,n1;
    cin>>n;
    d[1]=1;
    for(n1=1;n1<n;n1++)
    {
        scanf("%d%d",&t1,&t2);
        bian[t1].push_back(t2);
        bian[t2].push_back(t1);
    }
    dfs(1);
    cout<<sz[1]-mn[1]+1<<' '<<sz[1]-mx[1]+1<<endl;
}