#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n,m,a,b;
    cin >> n >> m >> a >> b;
    if(n % m == 0) return !printf("0");
    ll res = min((n - n / m * m) * b, ((n/m + 1) * m - n) * a);
    cout << res;
}