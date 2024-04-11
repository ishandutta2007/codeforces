#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
const int Q = 1e9 + 7;

void work() {
    int n , res = 1;
    cin >> n;
    -- n;
    for (int i = 0 ; i < n ; ++ i) {
        res *= (n + n - i);
        res /= i + 1;
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}