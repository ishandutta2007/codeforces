#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ld long double

const int N = 5e5 + 11;

ll a[N],s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
        s[i]=s[i-1]+a[i];
    int pos=1;
    ll ans=2e18;
    for (int i=1; i<=n; i++)
    if (a[i]!=a[i+1])
    {
        int kol=i-pos+1;
        if (kol>=k) {ans=0; break;}
        if (i>=k)
        {
            ll res=0;
            res+=(a[i]-1)*1ll*(pos-1)-s[pos-1];
            res+=k-kol;
            ans=min(ans,res);
        }
        if (kol+n-i>=k)
        {
            ll res=0;
            res+=s[n]-s[i]-(a[i]+1)*1ll*(n-i);
            res+=k-kol;
            ans=min(ans,res);
        }
        ll res=0;
        res+=(a[i]-1)*1ll*(pos-1)-s[pos-1];
        res+=s[n]-s[i]-(a[i]+1)*1ll*(n-i);
        res+=k-kol;
        ans=min(ans,res);
        pos=i+1;
    }
    cout<<ans;
}

/**

1 1 1 1 1  5 5 5 5 5

! 17

1 1 1 1 1  3 3 3 3 3  (+10)
1 1 2 2 2  2 2 2 2 3
**/