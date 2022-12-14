#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        ll x,y;
        cin>>x>>y;
        for (int i=1;i<=1000;i++) {
            if (x>=y)break;
            if (x%2)x--;
            x=x*3;
            x/=2;
            if (x>=y)break;
        }
        if (x>=y)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}