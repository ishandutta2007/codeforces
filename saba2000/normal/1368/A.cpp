#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,n;
        int ans = 0;
        cin >>a>>b>>n;
        while(a <= n && b <= n){
            if(a < b) a += b;
            else b += a;
            ans++;
        }
        cout<<ans<<endl;
    }


}