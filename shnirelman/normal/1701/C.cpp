#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 5000 + 13;
const int LOGN = 30;
const int L = 2001;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    vector<int> cnt(n, 0);
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;

        x--;

        cnt[x]++;
    }

    int l = 0, r = m * 2 + 2;
    while(r - l > 1) {
        int mid = (l + r) / 2;

        li res = 0;
        for(int i = 0; i < n; i++) {
            if(cnt[i] < mid)
                res += (mid - cnt[i]) / 2;
            else
                res -= cnt[i] - mid;
        }

        if(res < 0)
            l = mid;
        else
            r = mid;
    }

    cout << r << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}