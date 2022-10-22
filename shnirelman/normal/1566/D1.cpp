//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*

*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pii> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i].f;
        a[i].s = -i;
    }

//    sort(a.begin(), a.end());

    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j].f < a[i].f)
                ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}