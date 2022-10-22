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

/*
3 1
1 0 0
*/


signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> a(n);
    int lf = 0, rg = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
        lf += a[i].f;
        rg += a[i].s;
    }

    int ans = abs(rg - lf);
    int k = -1;

    for(int i = 0; i < n; i++) {
        int res = abs(rg - a[i].s + a[i].f - lf + a[i].f - a[i].s);
        if(res > ans) {
            ans = res;
            k = i;
        }
    }

    cout << k + 1 << endl;
}