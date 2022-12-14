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
int a[1000000];
int b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      int mn = 1e9;
      for (int i=1;i<=n;i++){
        cin>>a[i];
        b[i] = a[i];
        mn=min(mn,a[i]);
      }
      sort(a+1,a+n+1);
      bool ok = 1;
      for (int i=1;i<=n;i++){
        if (a[i]==b[i])continue;
        if (a[i]%mn) ok=0;
      }
      if (ok)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
}