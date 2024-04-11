#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll a[N],x,xx,y,yy,kk;

bool good(int k)
{
    int k1=k/xx;
    int k2=k/yy;
    ll p=(xx*yy)/(__gcd(xx,yy));
    int k3=k/p;
    k1-=k3;
    k2-=k3;
    ll sum=0;
    for (int i=1; i<=k; i++)
    if (k3>0) {k3--; sum+=a[i]/100ll*(x+y);} else
    if (k2>0) {k2--; sum+=a[i]/100ll*y;} else
    if (k1>0) {k1--; sum+=a[i]/100ll*x;}
    if (sum>=kk) return true;
    return false;
}

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    cin>>x>>xx>>y>>yy>>kk;
    if (x>y) {swap(x,y); swap(xx,yy);}
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int l=1,r=n;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) cout<<l<<"\n"; else
    if (good(r)) cout<<r<<"\n"; else cout<<"-1\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
        up();
}