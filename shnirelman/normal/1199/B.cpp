#include <bits/stdc++.h>

using namespace std;

int main() {
    long double l, h;
    cin >> h >> l;

    cout << setprecision(20) << fixed << (l * l - h * h) / 2 / h;
}