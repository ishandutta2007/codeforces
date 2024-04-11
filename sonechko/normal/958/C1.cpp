#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define ull unsigned long long
#define mp make_pair
const int N = 1e5 + 11;

int a[N],b[N];

int main()
{
    #ifndef __WIN32
    freopen("twopaths.in", "r", stdin);
    freopen("twopaths.out", "w", stdout);
    #endif // __WIN32
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,p;
    cin>>n>>p;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=(b[i-1]+a[i])%p;
    }
    int ans=0;
    for (int i=n; i>=2; i--)
    {
        b[i]=(b[i+1]+a[i])%p;
        ans=max(ans,b[i-1]+b[i]);
    }
    cout<<ans<<endl;
}