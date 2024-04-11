#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res;
    int k = (n) / 2;
    res = k * (k+1) + (n % 2 == 0 ? 0 : k + 1);
    cout << res;
}