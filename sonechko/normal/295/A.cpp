#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int N = 2e5 + 11;
const int MOD = 1e6 + 3;
#define mod %MOD
ll a[N],b[N],c[N],l[N],r[N],p[N];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
        cin>>l[i]>>r[i]>>p[i];
    for (int i=1; i<=k; i++)
    {
        int x,y;
        cin>>x>>y;
        c[x]++;
        c[y+1]--;
    }
    for (int i=1; i<=m; i++)
    {
        c[i]+=c[i-1];
        b[l[i]]+=p[i]*c[i];
        b[r[i]+1]-=p[i]*c[i];
    }
    for (int i=1; i<=n; i++)
    {
        b[i]+=b[i-1];
        cout<<b[i]+a[i]<<" ";
    }
    cout<<endl;
}