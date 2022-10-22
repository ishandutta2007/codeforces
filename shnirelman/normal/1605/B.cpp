//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 20;

/*
3 1
1 0 0
*/
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> cnt(2, 0);
    for(auto c : s)
        cnt[c - '0']++;

    vector<int> a;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0' && i >= cnt[0])
            a.push_back(i + 1);
        else if(s[i] == '1' && i < cnt[0])
            a.push_back(i + 1);
    }

    if(a.empty()) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl << a.size() << ' ';
        for(auto x : a)
            cout << x << ' ';
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}