#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL n;

int main() {
    cin >> n; LL nn = n;

    if (n == 1) {
        printf("%d\n", 1); return 0;
    }
    vector<LL> v;
    for (LL x = 2; x * x <= n; x ++) {
        if (n % x == 0) {
            v.push_back(x);
            while (n % x == 0) n /= x;
        }
    }
    if (n > 1) {
        v.push_back(n);
    }
    if (v.size() >= 2) {
        printf("1\n");
    } else {
        printf("%lld\n", v[0]);
    }
}