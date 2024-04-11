#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
    int n;
    cin>>n;
    ll x=0,y=0;
    for (int j=1; j<=n; j++)
        if (j<n/2) x+=1ll*(1<<j); else
        if (j<n) y+=1ll*(1<<j); else x+=1ll*(1<<j);
    cout<<abs(x-y)<<"\n";
    }
}