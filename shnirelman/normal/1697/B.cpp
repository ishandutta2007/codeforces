#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 32 + 13;
const int K = 513;
const int M = 1e9 + 7;
const int LOGN = 20;
const int A = 26;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<li> s(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i - 1];
    }

//    for(int i = 0; i <= n; i++) {
//        cout << i << ' ' << s[i] << endl;
//    }

    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

//        cout << "           " << x << ' ' << y << ' ' << n - y + x << ' ' << n - y << ' ' << s.size() << endl;

        cout << s[n - x + y] - s[n - x] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}