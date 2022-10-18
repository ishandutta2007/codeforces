#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

const int N = 1000 + 11;
const int MOD = 1e9 + 7;

int a[N],b[N];
bitset<N> c[N],c1,c2;

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

bool ins(int x1, int y1, int x2, int y2, ll r2)
{
    if (dist(x1,y1,x2,y2)<=r2*r2) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];
    for (int i=1; i<=m; i++)
    {
        int k,l,r;
        cin>>k>>l>>r;
        for (int j=1; j<=n; j++)
            if (ins(a[j],b[j],l,r,k)) c[j][i]=1;
    }
    for (int i=1; i<=k; i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<c[l].count()+c[r].count()-(c[l]&c[r]).count()*2ll<<"\n";
    }
}