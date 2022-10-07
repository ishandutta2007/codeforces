#include<bits/stdc++.h>
using namespace std;
bool p(long long a){
    for(long long i = 2; i * i <= a; i++){
        if(a % i == 0) return 0;
    }
    return 1;
}
main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long a, b;
        cin>> a>>b;
        if(b < a- 1) {
            cout << "NO"<<endl;
            continue;
        }
        if(p(a+b)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}