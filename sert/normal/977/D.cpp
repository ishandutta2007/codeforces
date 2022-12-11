#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (ll)2e5 + 34;
const int INF = (int)1e9 + 34;

int n3(ll x) {
    int res = 0;
    while (x % 3 == 0) {
        x /= 3;
        res++;
    }
    return res;
}

bool cmp(ll a, ll b) {
    int a3 = n3(a);
    int b3 = n3(b);
    return (a3 == b3 ? a < b : a3 > b3);
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++) {
        printf("%I64d ", a[i]);
    }
}

int main() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    //solve();
    solve();
    return 0;
}