#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 3e5 + 11;

int kk[N];
vector<int> a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        a[i].pb(0);
        for (int j=1; j<=m; j++)
        {
            int x;
            cin>>x;
            a[i].pb(x);
        }
    }
    int ans=0;
    for (int j=1; j<=m; j++)
    {
        for (int i=1; i<=n; i++)
            kk[i]=n+i-1;
        ///cout<<j<<": "<<endl;
        for (int i=1; i<=n; i++)
            if (a[i][j]%m==j%m&&a[i][j]<=n*m)
        {
            int x=a[i][j]/m+1;
            if (j==m) x--;
            int pos=i-(x-1);
            if (pos<=0) pos+=n;
            kk[pos]--;
           /// cout<<i<<": "<<a[i][j]<<": "<<x<<": -> "<<pos<<endl;
        }
        int res=2e9;
        for (int i=1; i<=n; i++)
            res=min(res,kk[i]);
       /// cout<<"+++"<<res<<endl;
        ans+=res;
    }
    cout<<ans;
}