#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if ((a + b) % 2 == 1) {
            cout << "-1\n";
            continue;
        }
        if (a == b) {
            cout << int(a > 0) << '\n';
            continue;
        } else {
            cout << "2\n";
            continue;
        }
    }
}