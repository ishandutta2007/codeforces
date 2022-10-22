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
    string s;
    cin >> s;

    int mx = 0;
    for(int i = 0; i < s.size(); i++) {
        mx = max(mx, s[i] - '0');
    }

    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}