#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5;

ll a[sz];

int main()
{
    ll i,j,k,n,m,x,y,l,total=0;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        scanf("%I64d", &a[i]);
        total+=a[i];
    }
    sort(a, a+n, greater<ll>());
    ll cur=a[0];
    ll ex=0,ans=0;
    for(i=0;i<=n;i++) {
        if(a[i]==cur) {
        }
        else {
            ll rem=cur-a[i];
            ans+=rem;
            ex-=rem;
            if(ex<0) ex=0;
        }
        cur=a[i];
        if(i<n) ex++;
    }
    ans+=ex;
    printf("%I64d\n", total-ans);
}