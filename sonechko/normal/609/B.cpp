#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N = 1e5 + 11;
int kol[N];

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        kol[l]++;
    }
    ll ans=1LL*n*(n-1)/2;
    for (int i=1; i<=m; i++)
        ans-=1LL*kol[i]*(kol[i]-1)/2;
    cout<<ans<<endl;
}