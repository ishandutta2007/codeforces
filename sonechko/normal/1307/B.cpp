#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int a[N];

void up()
{
    int n,x;
    cin>>n>>x;
    int ans=1e9;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (x==a[i]) ans=min(ans,1);
        if (x%a[i]==0) ans=min(ans,x/a[i]); else
        if (x>a[i]) ans=min(ans,(x/a[i])+1); else
        if (x<a[i]) ans=min(ans,2);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}