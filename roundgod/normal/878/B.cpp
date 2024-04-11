#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,m;
ll a[MAXN];
P st[MAXN];
int main()
{
    scanf("%I64d %I64d %I64d",&n,&k,&m);
    ll t=0;
    for(ll i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        if(t==0) st[t++]=P(a[i],1);
        else
        {
            P p=st[t-1];
            if(p.first==a[i])
            {
                t--;
                p.second++;
                if(p.second!=k)
                    st[t++]=p;
            }
            else st[t++]=P(a[i],1);
        }
    }
    ll cnt=0,s=0,res=0;
    for(ll i=0;i<t/2;i++)
    {
        if(st[i].first==st[t-1-i].first)
        {
            if(st[i].second+st[t-1-i].second>=k)
            {
                res++;
                if(st[i].second+st[t-1-i].second==k) {cnt++;continue;}
            }
        }
        break;
    }
    for(ll i=0;i<t;i++)
        s+=st[i].second;
    if(cnt>=(t+1)/2)
        if(m%2==0) printf("0\n"); else printf("%I64d\n",s);
    else if(t%2==1&&cnt==t/2)
        if((m*st[cnt].second)%k==0) printf("0\n"); else printf("%I64d\n",s-st[cnt].second+(m*st[cnt].second)%k);
    else
        printf("%I64d\n",m*s-(m-1)*res*k);
    return 0;
}