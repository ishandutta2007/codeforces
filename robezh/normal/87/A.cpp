#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int x, int y){
    return x == 0 ? y : gcd(y%x, x);
}

int main(){
    ll a,b;
    cin >> a >> b;
    ll res = 1LL * a * b / gcd(a,b);
    a = res / a, b = res / b;
    if(a < b) a++;
    else b++;
    if(a < b) cout << "Masha";
    else if(a == b) cout << "Equal";
    else cout << "Dasha";
}