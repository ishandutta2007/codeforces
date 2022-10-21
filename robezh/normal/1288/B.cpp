#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b;

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> a >> b;
        b++;
        int c = 0;
        while(b > 0) b /= 10, c++;
        cout << 1LL * (c - 1) * a << endl;
    }
}