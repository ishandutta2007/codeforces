#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 1e9 + 7;
const int B = 600;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    int cnt = 1;
    for(int i = 1; i < n; i++)
        cnt += (s[i] != s[i - 1]);

    int ans = n * a;
    if(b < 0)
        ans += (cnt / 2 + 1) * b;
    else
        ans += n * b;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}