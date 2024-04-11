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
const int N = 2e5 + 13;
const int LOGN = 10;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
4
1 2 3 4
1
1 5
*/

int p[N][A];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < A; j++) {
            p[i + 1][j] = p[i][j] + (s[i] == char('a' + j));
        }
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        l--;

        vector<int> used;
        for(int j = 0; j < A; j++) {
            if(p[r][j] - p[l][j] > 0)
                used.push_back(j);
        }

        if(used.size() <= 2 && r - l > 1 && s[l] == s[r - 1]) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }

//        if(r - l == 1 || p[r][s[l] - 'a'] - p[l][s[l] - 'a'] != r - l) {
//
//        } else {
//
//        }
    }

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}