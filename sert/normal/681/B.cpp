#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000 + 34;
typedef long double ld;

int a = 1234567;
int b = 123456;
int c = 1234;
int n;

int main() {
    cin >> n;
    for (int i = 0; i * a <= n; i++)
        for (int j = 0; i * a + j * b <= n; j++)
            if ((n - i * a - j * b) % c == 0) {
                cout << "YES\n";
                return 0;
            }
    cout << "NO\n";
    return 0;
}