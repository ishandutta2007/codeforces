#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1000 + 13;
const int K = 17;
const int M = 998244353;
const int LOGN = 20;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int k;
    cin >> k;

    set<char> st;
    for(int i = 0; i < k; i++) {
        char c;
        cin >> c;

        st.insert(c);
    }

    int ans = 0;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        if(st.count(s[i])) {
            ans = max(ans, cur);
            cur = 0;
        }

        cur++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}