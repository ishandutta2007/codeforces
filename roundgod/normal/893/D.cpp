#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
typedef long long ll;
ll n,d;
ll a[MAXN];
vector<ll> save;
int main()
{
    scanf("%I64d%I64d",&n,&d);
    for(ll i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    ll sum=0,cnt=0;
    ll lim=INF;
    for(ll i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            if(sum<0)
            {
                if(cnt!=0&&lim>=(-sum))
                {
                    lim+=sum;
                    sum=0;
                }
                else
                {
                    cnt++;
                    sum=0;
                    lim=INF;
                }
            }
        }
        sum+=a[i];
        if(sum>d)
        {
            printf("-1\n");
            return 0;
        }
        lim=min(lim,d-sum);
    }
    printf("%I64d\n",cnt);
    return 0;
}