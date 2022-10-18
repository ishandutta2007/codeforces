#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll k,n,s,p;
    cin>>k>>n>>s>>p;
    ll pp=(n+s-1)/s;
    pp*=k;
    cout<<(pp+p-1)/p<<endl;
}