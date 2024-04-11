#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll r,g,k;
        cin>>r>>g>>k;
        ll gg = __gcd(r,g);
        if (r<g)swap(r,g);
        if ((r-gg)/g + (((r-gg)%g)>0) >=k)cout<<"REBEL"<<endl;
        else cout<<"OBEY"<<endl;
    }
}