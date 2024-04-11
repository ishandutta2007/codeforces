#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>


using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const ll INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

int a[N], b[N];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    b[0] = 1;
    for (int i = 1; i < n; i++)
        b[i] = max(b[i - 1], a[i] + 1);
    for (int i = n - 2; i >= 0; i--)
        b[i] = max(b[i], b[i + 1] - 1);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += b[i] - a[i] - 1;
    cout << ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    solve();

}