#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            while(d >= i && a > 0)
                a--, ans++, d-=i;
        }
        cout<<ans<<endl;
    }


}