#include <bits/stdc++.h>
using namespace std;

int main(){
    long k, n, w;
    cin >> k >> n >> w;
    long price = k*w*(w+1)/2;

    if(price > n){
        cout << price - n;
    } else{
        cout << 0;
    }
    return 0;
}