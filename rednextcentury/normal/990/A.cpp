#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    ll L = n%m;
    ll R = (m-n%m)%m;
    cout<<min(R*a,L*b)<<endl;
}