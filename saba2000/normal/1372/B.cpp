#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int ans = n - 1, a = 1;
        for(int i = 1e5; i >= 2; i--){
            if(n % i == 0){
                a = n / i;
            }
        }
        cout<<a<<" "<<n-a<<endl;
    }


}