#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const int M = 1003;

ll n, a, sum, d[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
    }

    for (int i = 0; i < n; i++)
        cout << max(a + d[i] - sum - 1, 0ll) + max(d[i] + n - a - 1, 0ll) << " ";

    //return 0;
}