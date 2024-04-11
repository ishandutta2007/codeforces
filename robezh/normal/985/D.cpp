#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll E29 = (ll)2e9;

ll n,h;

ll sum(ll k){
    return (k+1) * k / 2;
}

bool check(ll k){
    return (k+1) * k / 2 <= n;
}

ll sum2(ll k){
    return (h+k) * (k-h+1) / 2 + k * (k-1) / 2;
}

bool check2(ll k){
    return sum2(k) <= n;
}

int main(){
    cin >> n >> h;
    if(h <= E29 && n >= (1+h) * h / 2){
        ll l = h, r = E29, mid;
        while(l+1 < r){
            mid = (l+r) / 2;
            if(check2(mid)) l = mid;
            else r = mid;
        }
        ll left = n - sum2(l);
        //cout << l << endl;
        if(left == 0) cout << 2 * l - h;
        else if(left <= l) cout << 2 * l - h + 1;
        else cout << 2 * l - h + 2;
        return 0;
    }
    ll l = 0, r = E29, mid;
    while(l + 1 < r){
        mid = (l+r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    if(n != (l+1)*l/2) cout << l+1;
    else cout << l;

}