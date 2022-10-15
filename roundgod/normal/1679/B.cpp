#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
int t[MAXN],tot,cur;
int main()
{
    scanf("%d%d",&n,&q);
    ll sum=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    tot=0;
    for(int i=0;i<q;i++)
    {
        int type,pos,x;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d",&pos,&x);
            int last=(t[pos]>=tot?a[pos]:cur);
            sum-=last; t[pos]=tot; a[pos]=x; sum+=x;
        }
        else
        {
            scanf("%d",&x);
            tot++; cur=x;
            sum=1LL*n*x;
        }
        printf("%lld\n",sum);
    }
    return 0;
}