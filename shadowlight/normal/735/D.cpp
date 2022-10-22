#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

bool pr(long long n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    long long n;
    cin >> n;
    if (pr(n)) {
        cout << 1;
        return 0;
    }
    if (n % 2 == 0 || pr(n - 2)) {
        cout << 2;
    } else{
        cout << 3;
    }
}