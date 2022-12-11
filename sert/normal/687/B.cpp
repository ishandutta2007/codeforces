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
const int N = 63e5 + 34;
const ll INF = 2e9 + 34;

bool u[N];

int main() {
    init();
    int n, x;
    vector <int> p;
    scanf("%d%d", &n, &x);
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            p.push_back(1);
            while (x % i == 0) {
                p.back() *= i;
                x /= i;
            }
        }
    }
    if (x > 1) {
        p.push_back(x);
    }
    while (n--) {
        scanf("%d", &x);
        for (int i = 0; i < (int)p.size(); i++)
            if (x % p[i] == 0)
                u[i] = true;
    }
    for (int i = 0; i < (int)p.size(); i++)
        if (!u[i]) {
            printf("No\n");
            return 0;
        }

    printf("Yes\n");
    return 0;
}