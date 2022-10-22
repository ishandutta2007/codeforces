#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int x = n % 10;
    for (int i = 1; i < 10; i++) {
        if ((x * i) % 10 == k || (x * i) % 10 == 0) {
            cout << i;
            return 0;
        }
    }
}