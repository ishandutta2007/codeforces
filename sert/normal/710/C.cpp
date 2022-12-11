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
const ll INF = 1e12;

int odd, ev;
int main() {
    init();

    int n, d;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (min(abs(i - n / 2), abs(j - n / 2)) % 2)
                cout << ++ev * 2;
            else
                cout << 1 + 2 * odd++;
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}