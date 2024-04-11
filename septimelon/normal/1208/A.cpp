#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, n, t;
    cin >> t;
    for (int qq = 0; qq < t; qq++) {
        cin >> a >> b >> n;
        if (n % 3 == 0) {
            cout << a << endl;
        }
        else if (n % 3 == 1) {
            cout << b << endl;
        }
        else {
            cout << (int)(a ^ b) << endl;
        }
    }
    return 0;
}