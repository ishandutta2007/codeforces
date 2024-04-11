#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN],b[MAXN];
int last[MAXN],cnt[MAXN],ans[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) last[i]=n;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        cnt[a[i]]++;
        last[a[i]]=min(last[a[i]],(b[i]-a[i]+n)%n);
    }
    for(int i=1;i<=n;i++) ans[i]=(cnt[i]-1)*n+last[i];
    for(int i=1;i<=n;i++)
    {
        int cur=0;
        for(int j=0;j<n;j++)
        {
            int v=(i+j); if(v>n) v-=n;
            if(cnt[v]) cur=max(cur,ans[v]+j);
        }
        printf("%d ",cur);
    }
    return 0;
}