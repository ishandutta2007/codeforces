#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll d[1000000];
ll h[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll x;
        cin>>n>>x;
        ll mx = -1e18;
        ll maxD=-1e18;
        for (int i=0;i<n;i++)
        {
            cin>>d[i]>>h[i];
            mx = max(mx,d[i]-h[i]);
            maxD = max(maxD,d[i]);
        }
        if (maxD>=x)
        {
            cout<<1<<endl;
            continue;
        }
        if (mx<=0)
        {
            cout<<-1<<endl;
            continue;
        }
        ll ret=1e18;
        for (int i=0;i<n;i++)
        {
            ll need = max(0LL,x-d[i]);
            ll num = need / mx + ((need%mx)>0);
            ret=min(ret,num+1);
        }
        cout<<ret<<endl;
    }
}