#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 5e5 + 11;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    if (n==1) return cout<<a[1],0;
    sort(a+1,a+n+1);
    if (a[1]>0&&a[n]>0)
    {
        ll s=0;
        for (int i=2; i<=n; i++)
            s+=a[i];
        s-=a[1];
        return cout<<s,0;
    }
    if (a[1]<0&&a[n]<0)
    {
        ll s=0;
        for (int i=1; i<n; i++)
            s-=a[i];
        s+=a[n];
        return cout<<s,0;
    }
    ll s=0;
    for (int i=1; i<=n; i++)
        if (a[i]<0) s-=a[i]; else s+=a[i];
    cout<<s;
}