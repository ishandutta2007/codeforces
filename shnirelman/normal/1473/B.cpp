#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;
using ld = long double;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    int k = n * m / __gcd(n, m);

    string a = "", b = "";
    for(int i = 0; i < k / n; i++)
        a += s;
    for(int i = 0; i < k / m; i++)
        b += t;

    cout << (a == b ? a : "-1") << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}