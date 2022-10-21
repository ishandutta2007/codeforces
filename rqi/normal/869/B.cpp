#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll a,b;
    int ans = 1;
    cin >> a >> b;
    if(b-a < 5){
        for(ll i = a+1; i <=b; i++){
            ans *= (i % 10);
            ans %= 10;
        }
        cout << ans;
    }
    else{
        cout << 0;
    }
}