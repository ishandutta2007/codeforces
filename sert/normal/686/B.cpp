#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.2
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
const int N = 1e6 + 34;
const int INF = 1e9 + 34;
typedef long long ll;

int n, a[N];

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                cout << j + 1 << " " << j + 2 << "\n";
                swap(a[j], a[j + 1]);
            }

    return 0;
}