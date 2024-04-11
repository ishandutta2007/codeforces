//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 20000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;

mt19937 rnd(time(0));

/*
1
8 5
2 1 7 4
4 2

*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> suf(n + 1, 0), p(n + 1, 0);
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] + b[i];
    }

    for(int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];

    int ans = INF;
    for(int i = 0; i < n; i++) {
        ans = min(ans, max(suf[i + 1], p[i]));
    }

    cout << ans << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}