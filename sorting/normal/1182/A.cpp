#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    
    cin >> n;
    
    if(n & 1){
        cout << "0" << endl;
        
        return 0;
    }
    
    cout << (1ll << (long long)(n / 2)) << endl;
    
    return 0;
}