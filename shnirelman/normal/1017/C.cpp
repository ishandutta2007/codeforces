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

/*
*/

void solve() {
    int n;
    cin >> n;

    int b = int(sqrt(n) + 0.001);
//    cout << b << endl;
    vector<vector<int>> res;
    for(int i = 0; i < n; i += b) {
//        cout << i << endl;
        res.push_back(vector<int> (0));
        for(int j = i; j < min(n, i + b); j++)
            res.back().push_back(j + 1);
    }

    for(int i = res.size() - 1; i >= 0; i--)
        for(auto x : res[i])
            cout << x << ' ';
    cout << endl;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}