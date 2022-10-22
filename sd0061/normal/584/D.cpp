#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
const int N = 100005;
const int Q = 1e9 + 7;
typedef long long LL;
using namespace std;

bool isprime(int x) {
    for (int i = 2 ; i * i <= x ; ++ i)
        if (x % i == 0)
            return 0;
    return 1;
}

int main() {
    int n ;
    cin >> n;
    if (n <= 5) {
        cout << 1 << endl << n << endl;
    } else {
        cout << 3 << endl << 3 << ' ';
        n -= 3;
        for (int i = 2; i <= n ; ++ i)
            if (isprime(i) && isprime(n - i)) {
                cout << i << ' ' << n - i << endl;
                break;
            }
    }
    return 0;
}