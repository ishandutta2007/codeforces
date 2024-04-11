#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int ans = -1, n, s, a, b, c;

int main() {
  //  freopen("a.in", "r", stdin);
    cin >> a >> b >> c;
    for (int i = 0; i < 2; i++) {
        swap(a, c);
        for (int j = 0; j < 2; j++)
            for (int ii = 0; ii < 2; ii++) {
                if (j == 0) n = a + b; else n = a * b;
                if (ii == 0) n = n + c; else n = n * c;
                ans = max(n, ans);
            }
    }
    cout << ans;
    return 0;
}