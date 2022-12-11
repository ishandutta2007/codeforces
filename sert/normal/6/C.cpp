#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

typedef int ll;

const ll N = 2e5 + 34;
char s[N];
ll a[N], c[N], b[N], ta;
ll n, m;

int main() {

    //freopen("a.in", "r", stdin);

    ///Test: #33, : 0 ., : 0 ,  : 0,   : 0, : CRASHED

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1) {
        cout << "1 0\n";
        return 0;
    }

    b[0] = 0;
    for (int i = 1; i < n; i++)
        b[i] = b[i - 1] + a[i - 1];
    c[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        c[i] = c[i + 1] + a[i + 1];
        if (c[i] >= b[i]) {
            cout << i + 1 << " " << n - i - 1 << "\n";
            return 0;
        }
    }

    return 0;
}