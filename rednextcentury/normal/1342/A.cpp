#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        b = min(b,a*2);
        ll ret = (max(x,y)-min(x,y))*a + min(x,y)*b;
        cout<<ret<<endl;
    }
}