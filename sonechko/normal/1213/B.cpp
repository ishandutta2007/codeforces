#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;

int a[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int x=2e9,ans=0;
    for (int i=n; i>=1; i--)
        if (a[i]>x) ans++; else x=a[i];
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}