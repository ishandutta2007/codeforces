#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define sqr(a) ((a)*(a))
#define ld long double
const int N = 1e5 + 11;
ld a[N],b[N];
int n;
ld m;
bool good(ld k)
{
    ld sums=0;
    for (int i=1; i<=n; i++)
        if (b[i]<a[i]*k) sums+=a[i]*k-b[i];
    if (sums>m*k) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ld sum=0;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i]>>b[i];
            sum+=a[i];
        }
    if (sum<=m) {cout<<"-1"<<endl; return 0;}
    ld l=0,r=1e18;
    while (r-l>0.0000001)
    {
        ld mid=(l+r)/2;
        if (good(mid)) l=mid; else r=mid;
    }
    cout.precision(10);
    cout<<fixed;
    if (good(r)) cout<<r<<endl; else cout<<l<<endl;
}