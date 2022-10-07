#include<bits/stdc++.h>
using namespace std;
int a[100009];
void solve(){
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] -= x;
    }
    sort(a+1, a+n+1);
    long long S = 0;
    for(int i = n; i >= 1; i--){
        S += a[i];
        if(S < 0) {cout << n - i << endl; return;}
    }
    cout<<n<<endl;
}

main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}