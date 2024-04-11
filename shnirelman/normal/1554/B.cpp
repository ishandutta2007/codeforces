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
const int N = 20000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;

mt19937 rnd(time(0));

/*
1
3 3
1 1 3
*/

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    li ans = -INF * 1ll * INF;
    for(int i = n - 1; i >= 0; i--) {
        if(i * 1ll * (i + 1) <= ans)
            break;
        for(int j = i - 1; j >= 0; j--) {
            ans = max(ans, (i + 1) * 1ll * (j + 1) - k * (a[i] | a[j]));
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();



//    for(int i = 0; i <= m; i++)
//        cout << (n ^ i) << ' ';
//    cout << endl;
}