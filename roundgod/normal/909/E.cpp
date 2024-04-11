#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,m;
vector<int> G[MAXN];
int a[MAXN];
int in[MAXN],out[MAXN],num[MAXN];
vector<int> order;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&y,&x);
        G[x].push_back(y);
        in[y]++,out[x]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)
        if(in[i]==0) q.push(i);
    while(q.size())
    {
        int x=q.front();
        q.pop();
        order.push_back(x);
        for(int i=0;i<G[x].size();i++)
            {in[G[x][i]]--; if(in[G[x][i]]==0) q.push(G[x][i]);}
    }
    memset(num,0,sizeof(num));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int p=order[i];
        for(int j=0;j<G[p].size();j++)
        {
            int x=G[p][j];
            if(a[p]==1&&a[x]==0) num[x]=max(num[x],num[p]+1);
            if(a[p]==1&&a[x]==1) num[x]=max(num[x],num[p]);
            if(a[p]==0&&a[x]==0) num[x]=max(num[x],num[p]);
            if(a[p]==0&&a[x]==1) num[x]=max(num[x],num[p]);
        }
    }
    bool f=false;
    for(int i=0;i<n;i++)
        if(a[i]==1) {f=true; ans=max(ans,num[i]);}
    if(!f) printf("0\n"); else printf("%d\n",ans+1);
    return 0;
}