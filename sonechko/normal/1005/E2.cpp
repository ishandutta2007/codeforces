#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 5e5 + 11;
const int MOD = 1e9 + 7;

int v[N],a[N],b[N],c[N];
int nn;

void update(int l, int r)
{
    for (int i=l; i<=nn; i=(i|(i+1)))
        v[i]+=r;
}

int sum(int l)
{
    int ans=0;
    for (int i=l; i>=0; i=(i&(i+1))-1)
        ans+=v[i];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    nn=n*2+4;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll ans=0;
    update(c[0]+n,1);
    for (int i=1; i<=n; i++)
    {
        if (a[i]<m) b[i]=-1; else b[i]=1;
        c[i]=c[i-1]+b[i];
        ans+=1ll*sum(c[i]+n-1);
        update(c[i]+n,1);
    }
    //cout<<ans<<endl;
    for (int i=0; i<=n; i++)
        update(c[i]+n,-1);
    update(c[0]+n,1);
    for (int i=1; i<=n; i++)
    {
        if (a[i]<=m) b[i]=-1; else b[i]=1;
        c[i]=c[i-1]+b[i];
        ans-=1ll*sum(c[i]+n-1);
        update(c[i]+n,1);
    }
    cout<<ans<<endl;
}
/**
4
1  4  5  60  4
-1 1  1  1   1

>0 - >=x

-1 -1 1 1 -1

>0 - >x

-1 0 1 1 0
1/ sum = 0|sum = 1
   0

**/