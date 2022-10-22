#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int k = min({a, b / 2, c / 4});
    cout << 7 * k;
}