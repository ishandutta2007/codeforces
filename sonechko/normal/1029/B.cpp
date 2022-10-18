#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int p=0;
    int ans=1;
    for (int i=1; i<=n; i++)
    {
        if (p<i-1) p++;
        while (p+2<=n&&a[p+2]<=a[p+1]*2)
            p++;
        ans=max(ans,p-i+2);
    }
    cout<<ans<<"\n";
}