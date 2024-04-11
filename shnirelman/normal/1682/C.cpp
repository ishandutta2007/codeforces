#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int K = 9;
const int M = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int c1 = 0, c2 = 0;
    for(auto p : mp) {
        if(p.s > 1)
            c2++;
        else
            c1++;
    }

    cout << c2 + (c1 + 1) / 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}