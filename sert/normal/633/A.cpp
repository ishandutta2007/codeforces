#include <bits/stdc++.h>
using namespace std;
bool u[123456];
int a, b, c, d;
int main() {
    cin >> a >> b >> c;
    for (int i = 0; i < 10000; i++)
        for (int j = 0; j < 10000; j++) {
            d = i * a + j * b;
            if (d > c)
                break;
            u[d] = true;
        }
    cout << (u[c] ? "Yes" : "No");
}