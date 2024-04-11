#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll ans = 1;
    int n;
    cin >> n;
    for(ll i = n; i >= n-4; i--){ans *= i;};
    for(ll i = 1; i <= 5; i++) ans /= i;
    for(ll i = n; i >= n-4; i--){ans *= i;}
    cout << ans;

}