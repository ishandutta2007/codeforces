/*
______     _   _                               _                
| ___ \   | | (_)                             | |               
| |_/ /___| |_ _ _ __ ___ _ __ ___   ___ _ __ | |_              
|    // _ \ __| | '__/ _ \ '_ ` _ \ / _ \ '_ \| __|             
| |\ \  __/ |_| | | |  __/ | | | | |  __/ | | | |_              
\_| \_\___|\__|_|_|  \___|_| |_| |_|\___|_| |_|\__|             
 
 
 _____      _   _       _      ___  _ _                       _ 
|_   _|    | \ | |     | |    / _ \| | |                     | |
  | | ___  |  \| | ___ | |_  / /_\ \ | | _____      _____  __| |
  | |/ __| | . ` |/ _ \| __| |  _  | | |/ _ \ \ /\ / / _ \/ _` |
 _| |\__ \ | |\  | (_) | |_  | | | | | | (_) \ V  V /  __/ (_| |
 \___/___/ \_| \_/\___/ \__| \_| |_/_|_|\___/ \_/\_/ \___|\__,_|
 
 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll TakeAll(ll &x, ll &y){
  ll ret = min(x,y);
  x-=ret;
  y-=ret;
  return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
      ll a0,a1,a2,b0,b1,b2;
      cin>>a0>>a1>>a2;
      cin>>b0>>b1>>b2;
      TakeAll(a0, b2);
      TakeAll(a2, b2);
      ll ret=0;
      ret+=2*TakeAll(a2,b1);
      ret-=2*TakeAll(a1,b2);
      cout<<ret<<endl;
    }
}