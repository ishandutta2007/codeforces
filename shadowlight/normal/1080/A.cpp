#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int x = (2 * n - 1) / k + 1;
    int y = (5 * n - 1) / k + 1;
    int z = (8 * n - 1) / k + 1;
    cout << x + y + z;
}