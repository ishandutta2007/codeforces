#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;

int s(long long n) {
    int ret = 0;
    while (n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}


int main() {
    long long n;
    cin >> n;
    long long a = 0;
    int ans = 0;
    while (a * 10 + 9 <= n) {
        ans = max(ans, s(a) + s(n - a));
        a = a * 10 + 9;
    }
    ans = max(ans, s(a) + s(n - a));
    cout << ans << "\n";
    return 0;
}