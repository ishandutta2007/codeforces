#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int A = 26;
const int B = 400;

int get(int x) {
    int res = 0;
    while(x > 0) {
        x /= 10;
        res++;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    multiset<int> ma(a.begin(), a.end()), mb(b.begin(), b.end());
    int ans = 0;

    while(!ma.empty()) {
        int x = *ma.rbegin();
        int y = *mb.rbegin();

        if(x >= y) {
            ma.erase(prev(ma.end()));

        }

        if(y >= x)
            mb.erase(prev(mb.end()));

        if(x != y) {
            ans++;
            if(x > y)
                ma.insert(get(x));
            else
                mb.insert(get(y));
        }

    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}