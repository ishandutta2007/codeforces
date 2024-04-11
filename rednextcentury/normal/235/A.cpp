#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll LCM(ll a,ll b){return a*b/__gcd(a,b);}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    if (n<=120){
        ll ret=0;
        for (ll i=1;i<=n;i++)
            for (ll j=1;j<=n;j++)
                for (ll k=1;k<=n;k++)
                    ret=max(ret,LCM(LCM(i,j),k));
        cout<<ret<<endl;
    }
    else{
ll ret=0;
        for (ll i=0;i<=100;i++)
            for (ll j=0;j<=100;j++)
                for (ll k=0;k<=100;k++)
                    ret=max(ret,LCM(LCM(n-i,n-j),n-k));
        cout<<ret<<endl;
}
}