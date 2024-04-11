#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,x;
    cin>>n>>x;
    int K = 0;
    for(int i = 1; i < n; i++){
        int a,b;
        cin>>a>>b;
        if(a == x || b == x) K++;
    }
    string fr = "Ayush", sc = "Ashish";
    if(K <= 1) {
        cout<<fr<<endl;
        return;
    }
    if((n - 2)%2==0) cout<<fr<<endl;
    else cout<<sc<<endl;
}
main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}