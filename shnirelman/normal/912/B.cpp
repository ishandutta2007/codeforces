#include <iostream>

using namespace std;

int main(){
    //for(int n = 1; n < 100; n++){
    long long n, k;
    cin >> n >> k;
    //int k = 2;
    long long n1 = n;
    long long ans;
    
    for(ans = 1; ans <= n; ans *= 2){}

    if(ans > n) ans--;
    if(k > 1)cout << ans;
    else cout << n;
}