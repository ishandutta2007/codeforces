#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x[200009];
main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k >> x[1];
        k -= x[1];
        ll g = 0;
        for(int i = 2 ; i <= n; i++){
            cin >> x[i];
            x[i] -= x[1];
            g = __gcd(g, x[i]);
        }
        if(k % g == 0){
            cout<<"YES"<<endl;
        }
        else cout<< "NO"<<endl;
    }
}