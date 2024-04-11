#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 2e5 + 11;

ll a[N],ans[N];

void up()
{
    ll n,m;
    cin>>n>>m;
    ll s=0;
    for (int i=1; i<=m; i++)
    {
        cin>>a[i];
        s+=1ll*a[i];
    }
    if (s<n) {cout<<"-1\n"; return;}
    ans[1]=1;
    ll l=1,r=a[1];
    s-=a[1];
    for (int i=2; i<=m; i++)
    {
        if (l+s>=n)
        {
            ans[i]=l+1;
            l=l+1;
            r=l+a[i]-1;
            if (r>n) {cout<<"-1\n"; return;}
            s-=a[i];
        } else
        {
            l=n-s;
            if (l>r+1) {cout<<"-1\n"; return;}
            l=l+1;
            r=l+a[i]-1;
            ans[i]=l;
            if (r>n) {cout<<"-1\n"; return;}
            s-=a[i];
        }
    }
    for (int i=1; i<=m; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    up();
}