#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll N,S;
ll s[MAXN],a[MAXN],b[MAXN];
pair<ll,ll> save[MAXN];

int main()
{
    scanf("%I64d %I64d",&N,&S);
    ll cnt=0,ans=0;
    for(int i=0;i<N;i++)
    {
        scanf("%I64d %I64d %I64d",&s[i],&a[i],&b[i]);
        save[i].first=a[i]-b[i];
        save[i].second=s[i];
        cnt+=s[i];
        ans+=b[i]*s[i];
    }
    ll rem=cnt%S;
    if(rem==0) rem=S;
    sort(save,save+N);
    ll p=0,q=0;
    int k=N-1;
    while(save[k].first>0&&k>=0)
    {
        p+=save[k].second;
        q+=save[k].first*save[k].second;
        k--;
    }
    ll rem2=p%S;
    if(rem2==0) rem2=S;
    if(rem2<rem)
    {
        ll ans1=q,ans2=q;
        ll d=rem2,t=k;
        k++;
        while(d>0&&k<N)
        {
            ans1-=min(d,save[k].second)*save[k].first;
            d-=min(d,save[k].second);
            k++;
        }
        d=rem-rem2;
        while(d>0&&t>=0)
        {
            ans2+=min(d,save[t].second)*save[t].first;
            d-=min(d,save[t].second);
            t--;
        }
        if(d!=0) q=ans1; else q=max(ans1,ans2);
    }
    printf("%I64d\n",ans+q);
    return 0;
}