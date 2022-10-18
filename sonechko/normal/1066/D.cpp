#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int a[N];


bool good(int x, int y, int kol, int sz)
{
    int t=sz;
    kol--;
    for (int i=x; i<=y; i++)
        if (t>=a[i]) t-=a[i]; else
    {
        if (kol==0) return false;
        kol--;
        t=sz;
        t-=a[i];
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int l=1,r=n;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid,n,m,k)) r=mid; else l=mid;
    }
    if (good(l,n,m,k)) cout<<n-l+1<<endl; else
    if (good(r,n,m,k)) cout<<n-r+1<<endl; else cout<<0<<endl;
}