#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double

const int N = 1e6 + 11;

ll a[N],b[N];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll res=1000000000000000000;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    for (int i=1; i<=m; i++)
    cin>>b[i];
    for (int i=1; i<=n; i++)
    {
              ll mx=-1000000000000000000;
              for (int j=1; j<=n; j++)
              for (int k=1; k<=m; k++)
              if (i!=j&&a[j]*b[k]>mx) mx=a[j]*b[k];
              res=min(res,mx);
    }
    cout<<res<<endl;
}