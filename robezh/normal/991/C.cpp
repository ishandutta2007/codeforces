#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

bool check(ll k){
    ll tot = 0, rem = n;
    while(rem > 0){
        tot += min(k, rem);
        rem -= min(k, rem);
        rem -= rem/10;
    }
    return tot * 2 >= n;

}

int main(){
    cin >> n;
    ll l = 0, r = n, mid;
    while(l + 1 < r){
        mid = (l+r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}