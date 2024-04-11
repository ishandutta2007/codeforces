#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1e6 + 11;

ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i=1; i<=14; i++)
        cin>>a[i];
    ll ans=0;
    for (int i=1; i<=14; i++)
        if (a[i]>0)
    {
        ll kk=a[i]/14,pp=a[i]%14;
        int cc=a[i];
        a[i]=0;
        ll rr=0;
        for (int d=i+1; d<=14; d++)
        {
            ll g=a[d]+kk;
            if (pp>0) {pp--; g++;}
            if (g%2==0) rr+=g;
        }
        for (int d=1; d<=i; d++)
        {
            ll g=a[d]+kk;
            if (pp>0) {pp--; g++;}
            if (g%2==0) rr+=g;
        }
        a[i]=cc;
        ans=max(ans,rr);
    }
    cout<<ans<<endl;
}