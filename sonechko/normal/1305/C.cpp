#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    if (n>m)
    {
        cout<<0;
        return 0;
    }
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=1;
    for (int i=1; i<=n; i++)
    for (int j=1; j<i; j++)
    {
        int p=abs(a[i]-a[j]);
        p%=m;
        ans=(ans*p)%m;
    }
    cout<<ans;
}