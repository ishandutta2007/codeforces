#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2e5 + 11;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll kk=0,pos=0;
    for (int j=1; j<=m; j++)
    {
        ll l;
        cin>>l;
        while (kk<l)
        {
            pos++;
            kk+=a[pos];
        }
        cout<<pos<<" "<<l-(kk-a[pos])<<"\n";
    }
}