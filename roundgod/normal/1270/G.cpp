#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
}
vector<int> ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            a[i]=i-a[i];
        }
        for(int i=1;i<=n;i++) vis[i]=false;
        int now=1;
        do
        {
            vis[now]=true;
            now=a[now];
        }while(!vis[now]);
        int u=now;
        ans.clear();
        do
        {
            ans.push_back(u);
            u=a[u];
        }while(u!=now);
        sort(ans.begin(),ans.end());
        printf("%d\n",(int)ans.size());
        for(auto x:ans) printf("%d ",x);
        puts("");
    }
    return 0;
}