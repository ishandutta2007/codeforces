#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define ll long long

int T, n;
ll a, b;
char s[200005];
ll f[200005][2];

int main()
{
    cin >> T;
    for (int data = 1; data <= T; data++) {
        cin >> n >> a >> b;
        cin >> (s + 1);
        f[0][0] = b;
        f[0][1] = 1000000000000000000LL;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1' || s[i+1] == '1') {
                f[i][0] = 1000000000000000000LL;
            } else {
                f[i][0] = min(f[i-1][0] + a + b, f[i-1][1] + a * 2 + b);
            }
            f[i][1] = min(f[i-1][0] + a * 2 + b * 2, f[i-1][1] + a + b * 2);
        }
        cout << f[n][0] << '\n';
    }
    return 0;
}