#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m;

int main() {
    ll ans = 1;
    cin >> n;
    if(n == 0) return !printf("0");
    n++;
    if(n % 2 == 1) cout << n;
    else cout << n / 2;
}