#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++)
        cin>>a[i];
    ll pos=1,ans=0;
    while (pos<=m)
    {
        ans++;
        ll c=pos;
        while (c+1<=m&&(a[pos]-(pos-1)+k-1)/k==(a[c+1]-(pos-1)+k-1)/k)
            c++;
        pos=c+1;
    }
    cout<<ans<<endl;
}