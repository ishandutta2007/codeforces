#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e3 + 11;
///------------------------
int k[N];
///------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        k[l]=1;
        k[r]=1;
    }
    for (int i=1; i<=n; i++)
        if (k[i]==0)
    {
        cout<<n-1<<endl;
        for (int j=1; j<=n; j++)
            if (j!=i) cout<<i<<" "<<j<<endl;
        return 0;
    }
}