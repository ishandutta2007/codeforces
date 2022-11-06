#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int main()
{
    ll n,i,j,k,x,y,z;
    cin >> n >> k;
    ll ans=k/n;
    if(k%n>0) ans++;
    cout << ans << endl;
}