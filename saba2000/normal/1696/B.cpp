#include<bits/stdc++.h>
using namespace std;
int n,z;
int a[100009];
void solve(){
    cin >> n;
    int ans = 0;
    int zr = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(zr == 0 && a[i] != 0) zr = 1; else
        if(zr == 1 && a[i] == 0) zr = 2; else
        if(zr == 2 && a[i] != 0) zr = 3;
    }
    if(zr == 3) cout << 2 << endl;
    else if(zr == 0) cout << 0<<endl;
    else cout<<1<<endl;

}
main(){
    int t; // = 1;
    cin >> t;
    while(t--){
        solve();
    }

}