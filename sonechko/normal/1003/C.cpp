#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int N = 1e5 + 11;

ll s[N],a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    cout.precision(10);
    cout<<fixed;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    ld ans=0;
    for (int i=1; i<=n; i++)
    for (int j=i+k-1; j<=n; j++)
    {
        ld p=(ld)(s[j]-s[i-1])/(ld)(j-i+1);
        ans=max(ans,p);
    }
    cout<<ans<<endl;
}