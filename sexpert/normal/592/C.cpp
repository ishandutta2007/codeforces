#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 6e18;
 
int main() {
    ll t, w, b;
    cin >> t >> w >> b;
    ll good = 0;
    if(w == b){
        cout << "1/1\n";
        return 0;
    }
    ll g = __gcd(w, b);
    if(w/g > INF/b)
        good = min(t + 1, min(w, b)) - 1;
    else {
        ll pd = w/g * b;
        ll cy = (t + 1)/pd;
        ll k = (t + 1)% pd;
        good = min(w, b) * cy + min(k, min(w, b));
        good--;
    }
    g = __gcd(good, t);
    cout << good/g << "/" << t/g << '\n';
}