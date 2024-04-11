#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c;

int main() {
    cin >> a >> b >> c;
    if(a % 2 != b % 2 || a % 2 != c % 2) {
        if(a % 2 != b % 2) {
            if(a % 2 == c % 2) swap(b, c);
            else swap(a, c);
        }
        cout << max(a, b) << endl;
    }
    else {
        cout << 1LL * a + b + c - max(a, max(b, c)) - min(a, min(b, c)) << endl;
    }
//    int dif = (a - b) / 2;
//    int res = 0;
//    if(dif <= c) {
//        cout << a << endl;
//        return 0;
//    }
//    res += c;
//    a -= c, b += c;

}