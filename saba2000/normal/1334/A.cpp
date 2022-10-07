#include<bits/stdc++.h>
using namespace std;
void solve(){
        int n;
        cin >> n;
        int P = -1, C = -1,ok=1;
        for(int i = 1; i <= n; i++){
            int p, c;
            cin >> p >> c;
            if(p < P || c < C){
                ok = 0;
            }
            if(p-P < c-C){
                ok = 0;
            }
            P=p; C=c;

        }
       if(ok) cout<<"YES"<<endl;else cout<<"NO"<<endl;

}
main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}