#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
//const int M = 1e9 + 7;
const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int mul(int a, int b) {
    return a * 1ll * b % M;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if(s[0] == 'R') {
        for(int i = 0; i < s.size(); i++) {
            s[i] = (s[i] ^ 'R' ^ 'D');
        }
    }

    int fir = 0;
    while(fir < s.size() && s[fir] == 'D')
        fir++;

    if(fir == s.size()) {
        cout << n << endl;
        return;
    }

    li cnt = 0;
    int cur = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'D')
            cnt += cur;
        else
            cur++;
    }

    cur = 0;
    for(int i = fir; i < s.size(); i++) {
        if(s[i] == 'R')
            cnt += cur;
        else
            cur++;
    }

    cnt += (n - 1) * 1ll * fir;

    cout << n * 1ll * n - cnt << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}