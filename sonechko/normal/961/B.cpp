#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
const int MOD = 1e9 + 7;
#define mod %MOD

const int N = 3e6 + 11;

int a[N],ss[N],s1[N],s2[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        ss[i]=ss[i-1]+a[i];
    }
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        if (b[i]==1) s1[i]=s1[i-1]+a[i]; else s1[i]=s1[i-1];
    }
    for (int i=n; i>=1; i--)
        if (b[i]==1) s2[i]=s2[i+1]+a[i]; else s2[i]=s2[i+1];
    int ans=0;
    for (int j=1; j<=n-k+1; j++)
        ans=max(ans,s1[j-1]+s2[j+k]+ss[j+k-1]-ss[j-1]);
    cout<<ans<<endl;
}