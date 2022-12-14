#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a,b;
    cin>>a>>b;
    if (a==b){
        cout<<"infinity"<<endl;
    } else if (a<b)cout<<"0"<<endl;
    else {
        ll x = a-b;
        int ret=0;
        for (ll i=1;i*i<=x;i++){
            if (x%i==0){
                if (i>b)
                ret++;
                if (i*i!=x && (x/i > b))ret++;
            }
        }
        cout<<ret<<endl;
    }
}