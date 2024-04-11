#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    typedef long long ll;
    ll mx = 49ll * n;
    set <ll> s;
    for(int i = 0; i < 1000; i ++) if(i <= mx) s.insert(i), s.insert(mx-i);
    for(int x = 0; x < 10; x ++) for(int y = 0; y < 50; y ++) for(int z = 0; z < 100; z ++) {
        if(x + y + z <= n) {
            ll val = 4 * x + 9 * y + 49 * z;
            s.erase(val);
        }
        if(z <= n && x + y + n-z <= n) {
            ll val = 4 * x + 9 * y + 49ll * (n-z);
            s.erase(val);
        }
    }
    cout << mx+1-s.size() << endl;
}