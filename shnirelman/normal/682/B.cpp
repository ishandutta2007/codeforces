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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int cur = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] >= cur)
            cur++;
    }
    cout << cur << endl;
}