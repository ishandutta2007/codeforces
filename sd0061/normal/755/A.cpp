#include <bits/stdc++.h>
using namespace std;

bool isprime(int x) {
    for (int i = 2 ; i * i <= x ; ++ i) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int m;
    cin >> m;
    for (int n = 1 ;  ; ++ n) {
        if (!isprime(n * m + 1)) {
            cout << n << endl;
            break;
        }
    }

}