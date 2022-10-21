#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = (n-1)/2; i > 0; i--){
        if(__gcd(i, n-i) == 1){
            cout << i << ' '<< n-i;
             break;
        } 
       
    }
}