#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1000 + 13;
const int K = 17;
const int M = 998244353;
const int LOGN = 20;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += (a[i] < 0);
    }

    for(int i = 0; i < n; i++) {
        if(i < cnt)
            a[i] = -abs(a[i]);
        else
            a[i] = abs(a[i]);
    }

    for(int i = 1; i < n; i++) {
        if(a[i] < a[i - 1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}