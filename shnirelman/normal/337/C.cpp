#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int M = 1e9 + 9;

int pow1(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow1(n, k / 2);

    if(k & 1)
        return pw * 1ll * pw % M * 1ll * n % M;
    else
        return pw * 1ll * pw % M;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    li a = n / k * 1ll * (k - 1) + n % k;

//    cout << a << endl;

    if(a >= m) {
        cout << m << endl;
        return 0;
    }

//    cout << a  << ' ' << m - a << ' ' << k - 1 << endl;
//    cout << pow(2, m - a) << endl;
    cout << ((k * 1ll * (pow1(2, m - a + 1) - 2)) % M +
              M +
              a - (m - a) * 1ll * (k - 1)) % M;
}