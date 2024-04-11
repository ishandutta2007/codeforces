#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,k;
vector<ll>v;
ll t=0;
bool chech(ll mid)
{
    for(int i=0;i<mid;i++)
    {
        if(v[n-mid+i]-v[i]<k)
            return false;
    }
    return true;

}

ll bin_search(ll st,ll ed)
{
    ll mid=(st+ed)/2;
    if(st==ed)
        return st;
    if(chech(mid))
    {
        if(!chech(mid+1))
            return mid;
        else
            return bin_search(mid+1,ed);
    }
    else
        return bin_search(st,mid-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0 ;i<n;i++)
    {
        ll x;cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

    return cout<<bin_search(0,n/2),0;

}