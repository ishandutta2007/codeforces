#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN],tot[MAXN];
int fund[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(tot,0,sizeof(tot));
    scanf("%d",&q);
    for(int i=1;i<=q+1;i++) fund[i]=-INF;
    for(int i=1;i<=q;i++)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            tot[x]=i;
            a[x]=y;
        }
        else
        {
            int x;
            scanf("%d",&x);
            fund[i]=x;
        }
    }
    for(int i=q+1;i>=0;i--) fund[i]=max(fund[i],fund[i+1]);
    for(int i=1;i<=n;i++)
    {
        int x=fund[tot[i]+1];
        printf("%d ",max(x,a[i]));
    }
    return 0;
}