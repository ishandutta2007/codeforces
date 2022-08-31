#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int a = 0, ab = 0, abc = 0, m = 1;
    for (char c : s) {
        if (c == 'a') {
            a = (a + m) % mod;
        } else if (c == 'b') {
            ab = (ab + a) % mod;
        } else if (c == 'c') {
            abc = (abc + ab) % mod;
        } else { // '?'
            abc = (3ll * abc + ab) % mod;
            ab = (3ll * ab + a) % mod;
            a = (3ll * a + m) % mod;
            m = (3ll * m) % mod;
        }
    }
    cout << abc << endl;
    return 0;
}