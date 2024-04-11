#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int ss=0;
    for (int i=1; i<=m; i++)
        {
            cin>>a[i];
            ss+=a[i];
        }
    sort(a+1,a+m+1);
    int ans=0;
    for (int i=0; i<=n; i++)
    {
        int ks=ss*i,kol=i*(m+1);
        vector<int> v;
        for (int j=i+1; j<=n; j++)
        for (int ii=1; ii<=m; ii++)
        v.pb(a[ii]);
        sort(v.begin(),v.end());
        for (int i=0; i<v.size(); i++)
            if (ks+v[i]<=k) {ks+=v[i]; kol++;}
        if (ks<=k) ans=max(ans,kol);
    }
    cout<<ans<<endl;
}