#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll tim = b;
        a -= b;
        if (a<=0) cout<<tim<<endl;
        else {
            if (c<=d)cout<<"-1"<<endl;
            else {
                ll num = c - d;
                ll need = (a + num-1) / num ;
                tim += need*c;
                cout<<tim<<endl;
            }
        }
    }
}