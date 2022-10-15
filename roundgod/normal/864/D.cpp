#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int a[MAXN],num[MAXN],pos[MAXN],ans[MAXN];
priority_queue<int, vector<int>, greater<int> > pque;
vector<int> G[MAXN];
bool used[MAXN];
int n;
int main()
{
    scanf("%d",&n);
    memset(used,false,sizeof(used));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        num[a[i]]++;
        G[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
        sort(G[i].begin(),G[i].end());
    for(int i=1;i<=n;i++)
        if(G[i].size()>1)
            for(int j=0;j<G[i].size()-1;j++)
                pque.push(G[i][j]);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(num[i]==0)
        {
            int x=pque.top();
            while(used[x]&&!pque.empty())
            {
                pque.pop();
                x=pque.top();
            }
            pque.pop();
            num[a[x]]--;
            pos[a[x]]++;
            ans[x]=i;
            cnt++;
        }
        else if(num[i]==1) ans[G[i][pos[i]]]=i;
        else
        {
            ans[G[i][pos[i]]]=i;
            used[G[i][pos[i]]]=true;
            pque.push(G[i][G[i].size()-1]);
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}