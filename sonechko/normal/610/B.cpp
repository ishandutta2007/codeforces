#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N = 2e5 + 11;
int a[N],b[N];

int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int mini=a[n],kk=n;
    for (int i=n; i>=1; i--)
    {
        if (a[i]<=mini) {mini=a[i]; kk=i;}
        b[i]=kk;
    }
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        int to=b[i];
        if (a[to]==mini) ans=max(ans,1LL*mini*n+to-i); else
        {
            to=b[1];
            ans=max(ans,1LL*mini*n+n-i+to);
        }
    }
    cout<<ans<<endl;
}