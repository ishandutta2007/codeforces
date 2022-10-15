#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef long long ll;
ll n;
ll a[MAXN];
ll cost1[MAXN],cost2[MAXN];
int main()
{
    scanf("%I64d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    memset(cost1,0,sizeof(cost1));
    memset(cost2,0,sizeof(cost2));
    ll sum=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        ll p=(ll)sqrt(a[i]);
        if(p*p==a[i])
        {
            cnt++;
            cost2[i]=a[i]==0?2:1;
        }
        else cost2[i]=0;
        cost1[i]=min(a[i]-p*p,(p+1)*(p+1)-a[i]);
    }
    if(cnt>n/2)
    {
        sort(cost2,cost2+n);
        for(int i=0;i<n/2;i++)
            sum+=cost2[i];
        printf("%I64d\n",sum);
        return 0;
    }
    else
    {
        sort(cost1,cost1+n);
        for(int i=0;i<n/2;i++)
            sum+=cost1[i];
        printf("%I64d\n",sum);
        return 0;
    }
}