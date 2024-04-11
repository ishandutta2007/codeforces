#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min({2*a + 2*b, 2*b + 2*c, 2*c + 2*a, a + b + c}) << endl;
}