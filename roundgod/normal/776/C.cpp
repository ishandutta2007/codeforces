#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[101005];
ll k_t[1000];
int main()
{
    int n,k,i,j,cnt;
    while(cin>>n>>k)
    {
        map<ll,int>mp;
        memset(f,0,sizeof(f));
        memset(k_t,0,sizeof(k_t));
        for(i=1;i<=n;i++)
        {
            cin>>f[i];
            f[i]+=f[i-1];
        }
        k_t[1]=1;cnt=2;
        if(k==-1)k_t[2]=-1,cnt++;
        else if(k!=1)
        {
            ll temp=k;
            while(temp<1e15)
            {
                k_t[cnt++]=temp;
                temp*=k;
            }
        }
        ll ans=0;
        for(i=1;i<cnt;i++)mp[k_t[i]]=1;
        for(i=1;i<=n;i++)
        {
            if(mp[f[i]])ans+=mp[f[i]];
            for(j=1;j<cnt;j++)
            mp[f[i]+k_t[j]]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}