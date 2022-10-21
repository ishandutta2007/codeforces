#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return a == 0 ? b : gcd(b % a, a);
}

ll a,b,x,y;

int main(){
    cin >> a >> b >> x >> y;
    ll g = gcd(x, y);
    x /= g, y /= g;
    ll res = min(a / x, b / y);
    cout << res << endl;
}