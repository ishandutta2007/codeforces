#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
bool vis[MAXN];
int a[MAXN],b[MAXN],pos[MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) pos[a[i]]=i;
        for(int i=1;i<=n;i++) vis[i]=false;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[a[i]]) continue;
            if(a[i]==b[i])
            {
                vis[a[i]]=true;
                continue;
            }
            int now=i;
            vis[a[i]]=true;
            while(b[now]!=a[i])
            {
                now=pos[b[now]];
                vis[a[now]]=true;
            }
            cnt++;
        }
        printf("%d\n",pow_mod(2,cnt));
    }
    return 0;
}