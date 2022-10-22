#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    LL n , a , b , p , q;
    cin >> n >> a >> b >> p >> q;
    LL A = n / a , B = n / b , c = a / __gcd(a , b) * b;
    LL C = n / c;
    A -= C , B -= C;
    cout << A * p + B * q + max(p , q) * C << endl;
}