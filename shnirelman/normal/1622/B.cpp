#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 998244353;//1e9 + 7;
const int A = 26;

mt19937 rnd(3432);


/*
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += s[i] - '0';
    }

    vector<int> b(n, -1);

    vector<pii> ord0, ord1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            ord0.emplace_back(a[i], i);
        } else {
            ord1.emplace_back(a[i], i);
        }
    }

    sort(ord0.begin(), ord0.end());
    sort(ord1.begin(), ord1.end());

    for(int i = 0; i < ord0.size(); i++) {
        b[ord0[i].s] = i + 1;
    }

    for(int i = 0; i < ord1.size(); i++) {
        b[ord1[i].s] = i + ord0.size() + 1;
    }

    for(int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}