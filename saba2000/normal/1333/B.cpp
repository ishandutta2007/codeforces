#include<bits/stdc++.h>
using namespace std;
int a[100009],b[100009];
void solve(){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int p = 0, m = 0;
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
        for(int i = 1;i  <= n; i++){
            if(b[i] > a[i] && !p){
                cout<<"NO"<<endl;
                return;
            }
            if(b[i] < a[i] && !m){
                cout<<"NO"<<endl;
                return;
            }
            if(a[i] == 1) p = 1;
            if(a[i] == -1)m = 1;
        }
        cout<<"YES"<<endl;

}
main(){
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}