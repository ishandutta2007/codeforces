#include <bits/stdc++.h>
using namespace std;

int n, m;
int p, q;

int main() {
    cin >> n;
    m = n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            int cnt = 0;
            p = 1;
            while(n % i == 0) {
                cnt++, n /= i;
                p *= i;
            }

            //power of prime
            if(n == 1) {
                return cout << "NO" << endl, 0;
            }
            q = n;
            break;
        }
    }

    if(n == m) return cout << "NO" << endl, 0;
    n = m;

    int x, y;
    for(x = 0; x < q; x++) {
        if((n - 1 - x * p) % q == 0) {
            y = (n - 1 - x * p) / q;
            break;
        }
    }
    cout << "YES\n2\n";
    cout << x << " " << q << endl;
    cout << y << " " << p << endl;

}