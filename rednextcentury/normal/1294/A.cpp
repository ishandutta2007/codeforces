#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,n;
        cin>>a>>b>>c>>n;
        ll mn = max(max(a,b),c);
        if ((a+b+c+n)%3==0 && (a+b+c+n)/3>=mn)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}