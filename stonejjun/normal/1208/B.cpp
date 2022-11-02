#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;

struct poi{
    ll idx,x,f,c;
};

poi arr[101010];
ll dp[101010];
ll brr[101010];

bool sf(poi a,poi b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.idx<b.idx;
}

bool sf2(poi a,poi b)
{
    return a.idx<b.idx;
}

priority_queue<pll,vector<pll>,greater<pll>> pq1;
priority_queue<pll,vector<pll>,less<pll>> pq2;


int main()
{
    ll t;
    ll i,j,k,l,m,n,a,b,c;
    ll cnt=0,chk=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i].x);
        arr[i].idx=i;
    }
    sort(arr+1,arr+1+n,sf);
    ll fr=0,fri=0;
    for(i=1;i<=n;i++)
    {
        if(arr[i].x!=arr[i-1].x)
        {
            fr=arr[i].idx;
            fri=i;

        }
        if(arr[i].x!=arr[i+1].x)
        {

            if(fri==i) continue;
            arr[i].f=fr;
            arr[fri].f=arr[i].idx;
        }
        if(arr[i].x==arr[i+1].x||arr[i].x==arr[i-1].x) arr[i].c=1;
    }

    sort(arr+1,arr+1+n,sf2);

    ll amaxi=0,amini=1e9+7,ans=1e9+7;
    ll bmaxi=0,bmini=1e9+7;
    for(i=1;i<=n;i++)
    {
        if(arr[i].f!=0)
        {
            if(arr[i].f>i)
            {
                amaxi=max(amaxi,i);
                amini=min(amini,i);
                pq1.push({i,arr[i].f});
            }
            else if(arr[i].f<i)
            {
                bmaxi=max(bmaxi,i);
                bmini=min(bmini,i);
                pq2.push({i,arr[i].f});
            }
        }
        else if(arr[i].c==1)
        {
            amaxi=max(amaxi,i);
            amini=min(amini,i);
            bmaxi=max(bmaxi,i);
            bmini=min(bmini,i);
            pq1.push({i,0});
            pq2.push({i,0});
        }
    }
    ans=min(ans,amaxi-amini);
    while(!pq1.empty()&&pq1.top().second!=0)
    {
        auto x=pq1.top(); pq1.pop();
        if(!pq1.empty())
        {
            //printf("a %lld %lld\n",amini,amaxi);
            pq1.push({x.second,0});
            amini=pq1.top().first;
            amaxi=max(amaxi,x.second);
            //printf("%lld %lld\n",amini,amaxi);

        }
        ans=min(ans,amaxi-amini);
    }

    ans=min(ans,bmaxi-bmini);
    while(!pq2.empty()&&pq2.top().second!=0)
    {
        auto x=pq2.top(); pq2.pop();
        if(!pq2.empty())
        {
            //printf("b %lld %lld\n",bmini,bmaxi);
            pq2.push({x.second,0});
            bmaxi=pq2.top().first;
            bmini=min(bmini,x.second);
            //printf("%lld %lld\n",bmini,bmaxi);

        }
        ans=min(ans,bmaxi-bmini);
    }
    if(ans==1e9+7||ans==-1e9-7) printf("0");
    else printf("%lld",ans+1);


}