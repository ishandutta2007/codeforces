#include<bits/stdc++.h>
#define int long long
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        int l,r,m;
        cin >> l >> r >>m;
        int L = max(1ll,m - r + l), R = m + r - l;
        for(int a = l; a <= r; a++){
            int n = (L + a - 1) / a;
            if(n * a > R) continue;
            int d = m - n * a;
            int b, c;
            if(d > 0) b = l, c = l + d;
            else b = r, c = r + d;
            cout << a <<" "<<c<<" "<<b<<endl;
            break;
        }
    }
    
}