#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    if (n % 2 == 1)
        cout << 0;
    else
        cout << (n / 2 - 1) / 2;

    return 0;
}