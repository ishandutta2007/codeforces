#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;

vector<pli> get(vector<int> a) {
    li cur = 0;
    li mn = 0;
    vector<pli> res;
    for(int i = 0; i < a.size(); i++) {
        cur += a[i];
        mn = min(mn, cur);

        if(cur > 0 || i + 1 == a.size()) {
            res.emplace_back(-mn, cur);
            cur = 0;
            mn = 0;
        }
    }

    return res;
}

void solve() {
    int n;
    cin >> n;


    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (i * 1ll * (j - i) % n + n + a[i]) % n << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--) {
        solve();
    }
}