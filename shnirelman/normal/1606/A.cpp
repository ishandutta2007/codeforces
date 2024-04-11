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

    if(s[0] != s[s.size() - 1]) {
        s[0] = s[s.size() - 1];
    }

//    int c0 = 0, c1 = 0;
//    for(int i = 0; i < s.size(); i++) {
//        if(s[i] != s[0])
//            break;
//        c0++;
//    }
//
//    for(int i = s.size() - 1; i >= 0; i--) {
//        if(s[i] != s[s.size() - 1])
//            break;
//        c1++;
//    }
//
//    if(c0 < c1) {
//        for(int i = 0; i < c0; i++)
//            s[i] = s[s.size() - 1];
//    } else {
//        for(int i = 0; i < c1; i++)
//            s[s.size() - 1] = s[0];
//    }

    cout << s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}