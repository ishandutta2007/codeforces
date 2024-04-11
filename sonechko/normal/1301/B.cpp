#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N];
int n;
int l1,r1;

bool good(int x)
{
    int l=0,r=2e9;
    for (int i=1; i<=n; i++)
        if (a[i]==-1)
    {
        if (i>1&&a[i-1]!=-1)
        {
            l=max(l,a[i-1]-x);
            r=min(r,a[i-1]+x);
        }
        if (i<n&&a[i+1]!=-1)
        {
            l=max(l,a[i+1]-x);
            r=min(r,a[i+1]+x);
        }
    } else
    {
        if (i>1&&a[i-1]!=-1&&a[i]!=-1&&abs(a[i]-a[i-1])>x) return 0;
    }
    l1=l;
    if (l<=r) return true;
    return false;
}

void up()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int l=0,r=1e9;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    int ans=0;
    if (good(l)) ans=l; else ans=r;
    int p=good(ans);
    cout<<ans<<" "<<l1<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}