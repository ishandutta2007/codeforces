#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef long double ld;

int n, m, l, r;
int a[100500];
int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        for (int j = l; j <= r; j++)
            a[j]++;
    }

    for (int i = 1; i <= n; i++)
        if (a[i] != 1) {
            cout << i << " " << a[i] << "\n";
            return 0;
        }
    cout << "OK\n";

    return 0;
}