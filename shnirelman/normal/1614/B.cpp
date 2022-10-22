#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}



void solve() {
    int n;
    cin >> n;

    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].f;
        a[i].s = i;
    }

    sort(a.rbegin(), a.rend());

    vector<int> x(n);
    int l = -1, r = 1;
    li ans = 0;
    for(int i = 0; i < n; i++) {
        int d = min(abs(l), r);
        ans += d * 2ll * a[i].f;

        if(abs(l) < r) {
            x[a[i].s] = l;
            l--;
        } else {
            x[a[i].s] = r;
            r++;
        }
    }

    cout << ans << endl;
    cout << 0 << ' ';
    for(int x1 : x)
        cout << x1 << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}