#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    if (n==1)
    {
        cout<<1<<' '<<0<<endl;
        return 0;
    }
    int ret=1;
    int mn=1000000,mx=0;
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0)
        {
            int num=0;
            ret*=i;
            while(n%i==0)n/=i,num++;
            mn=min(mn,num);
            mx=max(mx,num);
        }
    }
    if (n!=1)mn=min(mn,1),mx=max(mx,1),ret*=n;
    for (long long i=0;i<40;i++)
    {
        if ((1LL<<i)>=mx)
        {
            cout<<ret<<' '<<i+(mn!=(1LL<<i))<<endl;
            return 0;
        }
    }
}