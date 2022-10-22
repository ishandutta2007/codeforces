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
const int B = 600;

mt19937 rnd(36547);

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int l = -1, r = INF;
    while(r - l > 1) {
        int m = (l + r) / 2;
        int k = n + m;

        int k1 = k - k / 4;
        li sa = min(m, k1) * 100ll;
        li sb = 0;
        for(int i = 0; i < min(n, k1); i++)
            sb += b[i];
        for(int i = 0; i < min(n, k1 - m); i++)
            sa += a[i];

        if(sa >= sb)
            r = m;
        else
            l = m;
    }

    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}