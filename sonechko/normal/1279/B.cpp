#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll a[N],sum[N];

void up()
{
    int n;
    ll s;
    cin>>n>>s;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll sum=0;
    int pos=0;
    for (int i=1; i<=n; i++)
    {
        if (sum+a[i]>s) break;
        pos=i;
        sum+=a[i];
    }
    if (pos==n) {cout<<0<<"\n"; return;}
    int ans=pos;
    int t=1;
    for (int i=1; i<=pos+1; i++)
        if (a[i]>a[t]) t=i;
    sum=0;
    pos=0;
    for (int i=1; i<=n; i++)
    {
        if (i==t) continue;
        if (sum+a[i]>s) break;
        pos=i;
        sum+=a[i];
    }
    if (pos-1>ans) cout<<t<<"\n"; else cout<<0<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}