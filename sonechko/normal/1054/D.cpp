#include<bits/stdc++.h>
using namespace std;

#define ff first
#define pb push_back
#define ss second
#define mp make_pair
#define ll long long
#define mod %MOD

const int N = 7e6 + 11;
const int MOD = 1e9 + 7;

int a[300000];
int d[N][2];
int kol[N];
int kk;
int k;

void update(int x)
{
    int p=0;
    for (int j=0; j<k; j++)
    {
        int t=0;
        if (x&(1<<j)) t=1;
        if (d[p][t]==0) {kk++; d[p][t]=kk;}
        p=d[p][t];
    }
    kol[p]++;
}

int get(int x)
{
    int p=0;
    for (int j=0; j<k; j++)
    {
        int t=0;
        if (x&(1<<j)) t=1;
        if (d[p][t]==0) return 0;
        p=d[p][t];
    }
    return kol[p];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    update(0);
    int x=0;
    int al=(1<<k)-1;
    ll ans=0,ans1=0,ans2=0;
    for (int i=1; i<=n; i++)
    {
        x^=a[i];
        int c1=get(x),c2=get(x^al);
        if (c1>c2) {x^=al; swap(c1,c2);}
        ans+=1ll*(i-c1-c2);
        ans1+=1ll*c1;
        ans2+=1ll*c2;
        update(x);
    }
    cout<<ans+max(ans1,ans2)<<endl;
}