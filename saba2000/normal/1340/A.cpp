#include<bits/stdc++.h>
using namespace std;
int a[100009];
void solve(){
    int n;
    cin >> n;
    for(int i =1; i <= n; i++){
        cin >> a[i];
    }
    int M = a[n];
    for(int i= n-1; i >= 1; i--){
        if(a[i] < M && a[i] != a[i+1]-1){
            cout<<"NO"<<endl;
            return;
        }
        M = max(M, a[i]);
    }

    cout<<"YES"<<endl;


}
main(){
    int t;
    cin >>t;
    while(t--){
        solve();
    }

}