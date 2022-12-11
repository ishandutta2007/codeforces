#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

bool is_simple(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return true;
    return false;
}

int main() {
    init();

    int n;
    scanf("%d", &n);

    for (int i = 1; true; i++) {
        if (is_simple(n * i + 1)) {
            printf("%d", i);
            return 0;
        }
    }

    return 0;
}