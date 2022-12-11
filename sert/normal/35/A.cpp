#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int p, a, b;
    cin >> p;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b;
        if (a == p) p = b;
        else if (b == p) p = a;
    }
    cout << p;



    return 0;
}