#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef int64_t ll;

int main() {
    int x;
    cin >> x;
    int n = x;
    int mx = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            mx = i;
        }
        while (n % i == 0) {
            n /= i;
        }
    }
    mx = max(mx, n);
    int res = x;
    for (int i = x - mx + 1; i <= x ; ++i) {
        mx = 1;
        n = i;
        for (int j = 2; j * j <= n; ++j) {
            if (n % j == 0) {
                mx = j;
            }
            while (n % j == 0) {
                n /= j;
            }
        }
        if (n > 1) {
            mx = n;
        }
        if (n == i) {
            res = min(res, i);
        } else {
            res = min(res, i - mx + 1);
        }
    }
    cout << res;
    return 0;
}