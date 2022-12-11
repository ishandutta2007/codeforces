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

const int N = 504;

bool u[N][N];
bool ez[N];

int n, k;
int a[N];
int s2;

int main() {
    init();

    cin >> n >> k;

    if (k == 1 || k > 3 || n <= 3) {
        cout << -1;
        return 0;
    }

    if (k == 2) {
        if (n == 4) {
            cout << -1;
            return 0;
        }
        cout << n - 1 << "\n";
        for (int i = 1; i < n; i++)
            cout << i << " " << i + 1 << "\n";
        return 0;
    }

    if (k == 3) {
        cout << 3 + 2 * (n - 4) << "\n";
        cout << "1 2\n2 3\n3 4\n";
        for (int i = 5; i <= n; i++) {
            cout << i << " 1\n";
            cout << i << " 3\n";
        }
    }

    return 0;
}