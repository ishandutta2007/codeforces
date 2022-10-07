#include<bits/stdc++.h>
using namespace std;
int n,z;
int a[3009];
void solve(){
    cin >> n>>z;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans = max(ans, a[i]|z);}
    cout<<ans<<endl;;

}
main(){
    int t; // = 1;
    cin >> t;
    while(t--){
        solve();
    }

}