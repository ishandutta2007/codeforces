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

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;

    vector<int> cnt(256, 0);
    for(char x : a)
        cnt[x]++;
    for(char x : b)
        cnt[x]++;

    for(char x : c)
        cnt[x]--;

    bool fl = false;
    for(int x : cnt)
        if(x != 0)
            fl = true;

    cout << (fl ? "NO" : "YES") << endl;
}