#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
const int MOD = 1e9 + 7;
#define mod %MOD

const int N = 2e5 + 11;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k1,k2;
    cin>>n>>k1>>k2;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    for (int i=1; i<=k1; i++)
    {
        int pos=1;
        for (int j=1; j<=n; j++)
            if (abs(a[j]-b[j])>abs(a[pos]-b[pos])) pos=j;
        if (a[pos]<=b[pos]) a[pos]++; else a[pos]--;
    }
    for (int i=1; i<=k2; i++)
    {
        int pos=1;
        for (int j=1; j<=n; j++)
            if (abs(a[j]-b[j])>abs(a[pos]-b[pos])) pos=j;
        if (a[pos]<=b[pos]) b[pos]--; else b[pos]++;
    }
    ll ans=0;
    for (int j=1; j<=n; j++)
        ans+=(a[j]-b[j])*1ll*(a[j]-b[j]);
    cout<<ans<<endl;
}