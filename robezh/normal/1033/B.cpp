#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b;

bool is_prime(ll x){
    for(ll i = 2; i <= min(x - 1, (ll)1e6); i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a - b != 1) printf("NO\n");
        else{
            if(is_prime(a + b)) printf("YES\n");
            else printf("NO\n");
        }
    }
}