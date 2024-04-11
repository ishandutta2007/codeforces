#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int l[MAXN];
int st[MAXN],ed[MAXN];
bool ok[MAXN];
int bit[MAXM+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=MAXM)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
ll ans;
int main()
{
    scanf("%d",&n);
    memset(ok,true,sizeof(ok));
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&l[i]);
        int x;
        scanf("%d",&x);
        st[i]=x;
        for(int j=1;j<l[i];j++)
        {
            int y;
            scanf("%d",&y);
            if(x<y) ok[i]=false;
            x=y;
        }
        ed[i]=x;
    }
    ans=1LL*n*n;
    for(int i=1;i<=n;i++) if(ok[i]) add(st[i]+1,1);
    for(int i=1;i<=n;i++) if(ok[i]) ans-=sum(ed[i]+1);
    printf("%lld\n",ans);
    return 0;
}