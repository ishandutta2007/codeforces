#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long x;
    cin >> x;

    long long ret = LLONG_MAX, ret2;
    for (long long a=1; a*a<=x; a++)
        if (x % a == 0) {
            long long b = x / a;
            if (__gcd(a, b) == 1 && max(a, b) < ret)
                ret = max(a, b), ret2 = min(a, b);
        }

    cout << ret << " " << ret2 << "\n";

    return 0;
}