#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 3e5 + 11;

ll a[N],b[N],s1[N],s2[N],ss[N];

int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    for (int i=n; i>=1; i--)
    {
        ss[i]=ss[i+1]+a[i]+b[i];
        s1[i]=s1[i+1]+ss[i+1]+b[i]*(n-i+n-i+1);
        s2[i]=s2[i+1]+ss[i+1]+a[i]*(n-i+n-i+1);
        //cout<<i<<" "<<s1[i]<<" "<<s2[i]<<endl;
    }
    ll ans=0,sums=0,kol=0;
    for (int i=1; i<=n; i++)
    {
        if (i%2==1)
        {
            ans=max(ans,sums+s1[i]+ss[i]*kol);
            sums+=kol*a[i];
            kol++;
            sums+=kol*b[i];
            kol++;
        } else
        {
            ans=max(ans,sums+s2[i]+ss[i]*kol);
            sums+=kol*b[i];
            kol++;
            sums+=kol*a[i];
            kol++;
        }
    }
    cout<<ans<<endl;

}