#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;
const int MX = 2e18;

#define mod %MOD

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=0;
    for (int i=1; i<=n; i++)
        if (a[i]<=k) ans++; else break;
    for (int i=n; i>=1; i--)
        if (a[i]<=k) ans++; else break;
    if (ans==n*2) cout<<n<<endl; else cout<<ans<<endl;
}


/// 999 A