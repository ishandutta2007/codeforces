#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define MOD         1000000007
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        '\n'
#define PI          3.14159265359d
#define sz(x)       (int)x.size()
ll phi(ll n)
{
    ll i,res=n;
    for(i=2;i*i<=n;i++)
        if(n%i==0)
    {
        while(n%i==0)
            n/=i;
        res-=res/i;
    }
    if(n>1)
        res-=res/n;
    return res;
}
int main()
{
    ll n,k,res;
    cin>>n>>k;
    res=n;
    k=(k+1)/2;
    while(k--)
    {
        res=phi(res);
        if(res==1)
            break;
    }
    cout<<res%MOD;
    return 0;
}