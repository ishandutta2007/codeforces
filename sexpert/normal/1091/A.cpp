#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int d = min({a, b - 1, c - 2});
    cout << 3*d + 3 << endl;
}