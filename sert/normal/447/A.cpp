#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long n, a, b, ans, p;
bool u[100000];

int main() {
   // freopen("a.in", "r", stdin);
    cin >> p >> n;
    for (int i = 0; i < n; i++) {
        cin >> b;
        if (u[b % p]) {
            cout << i + 1;
            return 0;
        }
        u[b % p] = true;
    }
    cout << -1;
    return 0;
}