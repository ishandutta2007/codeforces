#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;while(t--){
    ll s,a,b,c;
    cin>>s>>a>>b>>c;
    ll bars = s/c;
    bars+=(bars/a)*b;
    cout<<bars<<endl;
    }
}