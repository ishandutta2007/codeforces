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

    string s;
    cin >> s;

    int ans = 0;
    for(int i = n / 2; i < n; i++) {
        if(s[i] == s[n / 2])
            ans++;
        else
            break;
    }

    cout << ans * 2 - n % 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}