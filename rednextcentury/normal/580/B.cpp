#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,k;pair<ll,ll>p[100100];ll mx=-INT_MAX;int l;
bool cheak(ll mid)
{
    if((p[mid].first-p[l].first)>=k)return 0;
    return 1;
}

ll bin_serch(ll st,ll ed)
{
    ll mid=(st+ed)/2;
    if(st==ed)return st;
    if(cheak(mid))
    {
        if(!cheak(mid+1))
            return mid;
        else
       return bin_serch(mid+1,ed);
    }
    else
        return bin_serch(st,mid);
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0 ;i<n ;i++)
    {
        ll x,c;cin>>x>>c;p[i].first=x;p[i].second=c;
    }
    sort(p,p+n);
    for(int i=1;i<n;i++)
    {
        p[i].second+=p[i-1].second;
    }
    for(int i=0 ;i<n;i++)
    {
        l=i;
        ll f=bin_serch(0,n-1);
        if(i==0)
        {
            if(mx<p[f].second)
                mx=p[f].second;
        }
         else
         {
           if(mx<(p[f].second-p[i-1].second))
            mx=p[f].second-p[i-1].second;
         }
    }
   cout<<mx<<endl;
}