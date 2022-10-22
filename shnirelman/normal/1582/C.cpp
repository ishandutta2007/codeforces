#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e7 + 13;
//const int M = 1e5 + 13;
const int A = 26;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = INF;
    for(char c = 'a'; c <= 'z'; c++) {
        int l = 0, r = n - 1;
        int res = 0;
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            } else if(s[l] == c) {
                res++;
                l++;
            } else if(s[r] == c) {
                res++;
                r--;
            } else {
                res = INF;
                break;
            }
        }

        ans = min(ans, res);
    }

    cout << (ans < INF ? ans : -1) << endl;
}

signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}