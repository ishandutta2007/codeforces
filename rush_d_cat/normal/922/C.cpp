#include <iostream>
using namespace std;
typedef long long LL;
LL n, k;
int main() {
    cin >> n >> k;
    bool ok = 1;
    for (LL x = 1; x <= k; x ++) {
        if (n % x != (x - 1)) {
            ok = 0; break;
        }
    }
    printf("%s\n", ok ? "Yes" : "No");

}