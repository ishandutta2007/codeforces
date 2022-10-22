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
const int N = 1000 + 13;
const int LOGN = 20;
const int K = 12;
const int M = 1e9 + 7;
//const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

int mul(int a, int b) {
    return a * 1ll * b % M;
}

/*
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> res(64, 1);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < 6; j++) {
            if(((1 << j) & i) == 0)
                res[i] *= 3;
        }
    }

    int ans = 1;
    for(char c : s) {
        if('0' <= c && c <= '9')
            ans = mul(ans, res[c - '0']);
        else if('A' <= c && c <= 'Z')
            ans = mul(ans, res[c - 'A' + 10]);
        else if('a' <= c && c <= 'z')
            ans = mul(ans, res[c - 'a' + 36]);
        else if(c == '-')
            ans = mul(ans, res[62]);
        else
            ans = mul(ans, res[63]);
    }

    cout << ans << endl;
}