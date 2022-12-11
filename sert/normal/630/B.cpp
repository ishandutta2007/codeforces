#include <bits/stdc++.h>
using namespace std;
const int N = 5012;
long double x = 1.000000011;
int n, t;
int main() {
    cin >> n >> t;
    long double a = 1;
    for (int i = 0; i < 100000; i++) a *= x;
    long double b = 1;
    for (int i = 0; i < t / 100000; i++) b *= a;
    for (int i = 0; i < t % 100000; i++) b *= x;
    cout.precision(20);
    cout << fixed << b * n;
}