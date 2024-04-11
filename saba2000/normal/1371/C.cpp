#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, n, m;
        cin >> a >> b >> n >> m;
        if(n + m > a + b || min(a, b) < m){
            cout << "NO" <<endl;
        }
        else cout <<"YES"<<endl;

    }

}