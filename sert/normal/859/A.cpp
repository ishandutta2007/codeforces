#include <bits/stdc++.h>
#define y1 yy1
using namespace std;
const int N = (int)1e6 + 34;
const int M = 103;
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-14;
const ll P = 41;
const ll MD = (ll)1e9 + 9;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif // FIRE_MIND
}

int a[N];
int n, mx = -1;

int main() {
    init();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    cout << max(mx - 25, 0);

    return 0;
}