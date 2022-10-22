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

/*
1
5
1 2 1 2 3
*/


signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, w;
    cin >> n >> w;

    vector<int> a(n * 2);
    for(int i = 0; i < n * 2; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int x = a[0], y = a[n];

//    y = min(y, x * 2);

    cout << setprecision(20) << fixed << min(ld(w), min(ld(x) * 3 * n, ld(y) * 1.5 * n)) << endl;
}