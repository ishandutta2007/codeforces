#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin>>k;
    while (k--)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        int ans=0;
        for (int i=n; i>=1; i--)
            if (a[i]>=n-i+1) ans=n-i+1;
        cout<<ans<<"\n";
    }
}