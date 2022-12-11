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

int ans = N, n, a[N], b[N];
string s[N];
bool fail;

int main() {
    //init();
    int x;
    cin >> x;
    if (x < 0) x = -x;

    int n = 0;
    int sum = 0;

    while (sum % 2 != x % 2 || sum < x) {
        sum += ++n;
    }

    cout << n;

    return 0;
}