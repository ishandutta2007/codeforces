#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    int mna = 100, mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mna = min(mna, a[i]);
    }

    vector<int> b(m);
    int mnb = 100;
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        mnb = min(mnb, b[i]);
    }

    int ans = max(mna * 2, mx);
    if(mnb <= ans)
        cout << -1;
    else
        cout << ans;
}