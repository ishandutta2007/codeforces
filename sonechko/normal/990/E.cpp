#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int b[N],c[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0; i<=n; i++)
        b[i]=i;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        if (l==0) {cout<<-1<<endl; return 0;}
        b[l]=b[l-1];
    }
    ll res=1000000000000000000;
    for (int i=1; i<=k; i++)
        cin>>c[i];
    for (int i=1; i<=k; i++)
    {
        int d=0,kol=0;
        while (d<n)
        {
            //cout<<i<<" "<<d<<endl;
            kol++;
            d+=i;
            if (d>=n) break;
            int p=b[d];
            if (p==d-i) break;
            d=p;
        }
        if (d>=n) res=min(res,c[i]*1ll*kol);
    }
    if (res==1000000000000000000) cout<<-1<<endl; else cout<<res<<endl;
}