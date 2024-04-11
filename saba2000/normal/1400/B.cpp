#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--){
        ll cx,cy,wx,wy,x,y;
        cin>>cx>>cy>>x>>y>>wx>>wy;
        if(wx>wy) swap(x,y),swap(wx,wy);
        ll pas=0;
        for(ll i = 0; (i * wx <= cx && i <= x); i++){
            ll X = x,Y=y,CX=cx,CY=cy;
            ll ans=  0;
            ans += i;
            CX -= i*wx;
            X -= i;
            ans += min(Y,CX / wy);
            Y -= min(Y,CX / wy);
            ans += min(X, CY/wx);

            CY -= min(X, CY/wx) * wx;
            ans += min(Y, CY/wy);
            pas= max(ans, pas);
        }
        cout<<pas<<endl;
    }

}