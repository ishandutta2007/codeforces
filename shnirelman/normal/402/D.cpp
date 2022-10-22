#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 5000 + 13;

int a[N], b[N];
set<int> s;

int get(int x) {
    int res = 0;
//cout << x << ' ';
    for(int i = 2; i * 1ll * i <= x; i++) {
        while(x % i == 0) {
            x /= i;
            res += (s.count(i) ? -1 : 1);
        }
    }

    if(x > 1) {
        res += (s.count(x) ? -1 : 1);
    }
//cout << res << endl;
    return res;
}

int g[N];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
        s.insert(b[i]);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans += get(a[i]);
    }

//    cout << ans;

    for(int i = 0; i < n; i++) {
        g[i] = __gcd(i > 0 ? g[i - 1] : 0, a[i]);
    }

    int res = ans;
    int d = 1;
    for(int i = n - 1; i >= 0; i--) {
        int x = get(g[i] / d);
        if(x < 0) {
            ans -= x * (i + 1);
            d = g[i];
        }

    }

    cout << ans;
}