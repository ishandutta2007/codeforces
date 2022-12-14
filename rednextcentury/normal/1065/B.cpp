#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    ll mn = max(0LL,n-(m*2));
    ll mx = 0;
    while(mx*(mx-1)/2 < m)
        mx++;
    mx=n-mx;
    cout<<mn<<' '<<mx<<endl;
}