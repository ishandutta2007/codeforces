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
const int N = 1e5 + 13;
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

    int n;
    cin >> n;

    if(n % 2 == 0) {
        cout << -1 << endl;
    } else {
        for(int i = 0; i < n; i++)
            cout << i << ' ';
        cout << endl << n - 1 << ' ';
        for(int i = 0; i < n - 1; i++)
            cout << i << ' ';
        cout << endl << n - 1 << ' ';
        for(int i = 0; i < n - 1; i++)
            cout << (i + 1 + i) % n << ' ';
        cout << endl;
    }
}