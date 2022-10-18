#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 1e6 + 11;

ll a[N],b[N],num[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll sum=0,ans=0;
    for (int i=1; i<=n; i++)
        sum+=a[i];
    for (int i=1; i<=m; i++)
        cin>>b[i];
    sort(b+1,b+m+1);
    if (a[n]>b[1]) {cout<<"-1"<<endl; return 0;}
    int pos=0;
    for (int i=1; i<=m; i++)
    ans+=sum+b[i]-a[n];
    if (a[n]!=b[1]) ans+=a[n]-a[n-1];
    cout<<ans<<"\n";
}