#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    long long k;
    cin >> k;
    int x = 1;
    while (k % 2 == 0) {
        k /= 2;
        x++;
    }
    cout << x;
}