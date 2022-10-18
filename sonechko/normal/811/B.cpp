#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int a[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int j=1; j<=m; j++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        int kol=0;
        for (int i=l; i<=r; i++)
            if (a[i]<a[x]) kol++;
        if (l+kol==x) cout<<"Yes\n"; else cout<<"No\n";
    }
}