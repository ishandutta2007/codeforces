#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s[200009];
ll a[200009];
main(){
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s[i] = s[i-1] + a[i];
        }
        if(k > n){
            cout << s[n] + (k-1) * n - n * (n - 1)/2 << endl;
        }
        else{
            ll M = 0;
            for(int i = k; i <= n; i++){
                M = max(M, s[i] - s[i-k]);
            }
            cout<<M+k*(k-1)/2<<endl;
        }
    }
}
/*
K


124
*/