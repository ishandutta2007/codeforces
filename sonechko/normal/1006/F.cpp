#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 100 + 11;

ll a[N][N];
int n,m;
ll k;
map<ll,ll> mt[N][N];
ll ans;

void rec1(int l, int r, int dist, ll mm)
{
    if (l>n||r>m) return;
    mm^=a[l][r];
    dist--;
    if (dist==-1)
    {
        mt[l][r][mm]++;
        ///cout<<l<<" "<<r<<" + "<<mm<<endl;
        return;
    }
    rec1(l+1,r,dist,mm);
    rec1(l,r+1,dist,mm);
}

void rec2(int l, int r, int dist, ll mm)
{
    if (l<1||r<1) return;
    dist--;
    if (dist==-1)
    {
        ll p=(k^mm);
        /**
        cout<<l<<" "<<r<<" ? "<<mm<<endl;
        cout<<"? "<<p<<endl;
        cout<<"+ "<<mt[l][r][p]<<endl;
        cout<<endl;
        **/
        ans+=mt[l][r][p];
        return;
    }
    mm^=a[l][r];
    rec2(l-1,r,dist,mm);
    rec2(l,r-1,dist,mm);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cin>>a[i][j];
    int dist1=(n-1+m-1)/2;
    int dist2=(n-1+m-1+1)/2;
    rec1(1,1,dist1,0);
    rec2(n,m,dist2,0);
    cout<<ans<<endl;
}