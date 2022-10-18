#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double
#define pb push_back
const int N = 2e5 + 11;

int n;
ld x[N],v[N];

bool good(ld h)
{
    ld mini=-2e9;
    ld maxi=2e9;
    for (int i=1; i<=n; i++)
    {
        ld xx=x[i]-h*v[i];
        ld yy=x[i]+h*v[i];
        mini=max(mini,xx);
        maxi=min(maxi,yy);
    }
    if (mini<=maxi+0.0000001) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>x[i];
    for (int i=1; i<=n; i++)
        cin>>v[i];
    ld l=0,r=1e9;
    while (r-l>0.0000001)
    {
        ld mid=(l+r)/(ld)2;
        if (good(mid)) r=mid; else l=mid;
    }
    cout.precision(10);
    cout<<fixed;
    cout<<l<<endl;
}