#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 5e5 + 11;

int a[N],b[N],s[N],h;

bool good(int l, int r)
{
    int dist=b[r]-a[l];
    dist-=s[r]-s[l-1];
    if (dist<h) return true;
    return false;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n>>h;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        s[i]=s[i-1]+b[i]-a[i];
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int l=i,r=n;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (good(i,mid)) l=mid; else r=mid;
        }
        if (good(i,r)) l=r;
        int dist=b[l]-a[i];
        dist-=s[l]-s[i-1];
        //cout<<i<<"->"<<l<<" "<<b[l]-a[i]<<" + "<<h-dist<<endl;
        ans=max(ans,b[l]-a[i]+h-dist);
    }
    cout<<ans<<endl;
}