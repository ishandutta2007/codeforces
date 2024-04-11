#include<bits/stdc++.h>
using namespace std;

#define ll long long 

const int N = 1e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);       
    int n;
    cin>>n;
    ll ans=0;
    for (int i=2; i<=n; i++) 
      ans+=i*4ll*(n/i-1);
    cout<<ans<<endl;
}