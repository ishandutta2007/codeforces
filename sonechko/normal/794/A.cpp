#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int aa[N];
int main()
{
    int a,b,c,n,ans=0;
    cin>>b>>a>>c>>n;
    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        if (k>a&&k<c) ans++;
    }
    cout<<ans<<endl;
}