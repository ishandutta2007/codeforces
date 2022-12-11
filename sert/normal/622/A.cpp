#include <bits/stdc++.h>
using namespace std;
int n, cur, s1, s2;
bool u;
int main() {
    long long n;
    cin >> n;
    for (long long i = 1; true; i++) {
        if (n <= i) {
            cout << n;
            return 0;
        }
        n -= i;
    }
}