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
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const ld eps = 1e-6;
const int B = 300;
const int K = 400;
const int LOGN = 20;



/*
*/

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> cnt(26, 0);
    for(int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    for(int i = 0; i < n; i++) {
        cnt[s[i] - 'a']--;

        if(cnt[s[i] - 'a'] == 0) {
            cout << s.substr(i, n - i) << endl;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}