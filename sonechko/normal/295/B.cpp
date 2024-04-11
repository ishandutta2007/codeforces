#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int N = 2000 + 11;

ll a[N][N],b[N];
bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    cin>>a[i][j];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    vector<ll> vv;
    for (int i=n; i>=1; i--)
    {
        use[b[i]]=1;
        for (int j=1; j<=n; j++)
        for (int k=1; k<=n; k++)
        if (j!=b[i]&&k!=b[i]&&
            a[j][k]>a[j][b[i]]+a[b[i]][k])
            a[j][k]=a[j][b[i]]+a[b[i]][k];
        ll res=0;
        for (int j=1; j<=n; j++)
        for (int k=1; k<=n; k++)
        if (use[j]&&use[k]) res+=a[j][k];
        vv.pb(res);
    }
    for (int j=vv.size()-1; j>=0; j--)
        cout<<vv[j]<<" ";
    cout<<endl;
}