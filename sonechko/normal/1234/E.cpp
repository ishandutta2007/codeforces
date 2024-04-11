#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll s[N],x[N];

void up(int l, int r, ll x)
{
    s[l]+=x;
    s[r+1]-=x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
        cin>>x[i];
    for (int i=2; i<=m; i++)
    {
        int l=x[i-1];
        int r=x[i];
        if (l>r) swap(l,r);
        if (l!=r)
        {up(1,l-1,r-l);
        up(l,l,r-1);
        up(l+1,r-1,r-l-1);
        up(r,r,l);
        up(r+1,n,r-l);}
    }
    for (int i=1; i<=n; i++)
    {
        s[i]+=s[i-1];
        cout<<s[i]<<" ";
    }
    cout<<endl;
}