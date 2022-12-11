#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;

int n, k;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;

    cout << (n * 6 - 1) * k << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cout << (i * 6 + j + 1) * k << " ";
        cout << (i * 6 + 5) * k << "\n";
    }

    return 0;
}