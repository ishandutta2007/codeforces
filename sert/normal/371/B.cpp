#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const int M = 200;

int fv(int x, int d) {
    int as = 0;
    while (x % d == 0) {
        as++;
        x /= d;
    }
    return as;
}

int a, b;
int a5, b5, a3, b3, a2, b2;
int ans;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> a >> b;
    a5 = fv(a, 5);
    a3 = fv(a, 3);
    b5 = fv(b, 5);
    b3 = fv(b, 3);



    for (int i = 0; i < a5 - b5; i++) {
        a /= 5;
        ans++;
    }
    for (int i = 0; i < b5 - a5; i++) {
        b /= 5;
        ans++;
    }
    for (int i = 0; i < a3 - b3; i++) {
        a /= 3;
        ans++;
    }
    for (int i = 0; i < b3 - a3; i++) {
        b /= 3;
        ans++;
    }

    a2 = fv(a, 2);
    b2 = fv(b, 2);
    for (int i = 0; i < a2 - b2; i++) {
        a /= 2;
        ans++;
    }
    for (int i = 0; i < b2 - a2; i++) {
        b /= 2;
        ans++;
    }

    if (a == b) {
        cout << ans << "\n";
        return 0;
    }

    cout << -1 << "\n";

    //return 0;
}