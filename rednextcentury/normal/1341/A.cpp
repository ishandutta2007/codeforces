#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        ll L = (a-b)*n;
        ll R = L + 2*b*n;
        L = max(L, c-d);
        R = min(R, c+d);
        if (L<=R)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}