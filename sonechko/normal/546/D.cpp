#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e6 + 11;

int a[N],use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int m=5e6;
    for (int i=2; i<=m; i++)
    if (use[i]==0)
    {
        a[i]=1;
        for (ll j=1LL*i*i; j<=m; j+=i)
            if (use[j]==0) use[j]=i;
    } else a[i]=a[i/use[i]]+1;
    for (int i=1; i<=m; i++)
        a[i]=a[i-1]+a[i];
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<a[l]-a[r]<<"\n";
    }
}