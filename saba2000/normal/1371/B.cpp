#include<bits/stdc++.h>
using namespace std;
main(){
    long long n, r;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> r;
        r = min(r, n);
        if(r == n) cout << r*(r-1)/2+1<<endl; else
        cout << r * (r+1)/2<<endl;
    }

}