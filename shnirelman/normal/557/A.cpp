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

    int n, mn1, mx1, mn2, mx2, mn3, mx3;
    cin >> n >> mn1 >> mx1 >> mn2 >> mx2 >> mn3 >> mx3;

    for(int i = mx1; i >= mn1; i--) if(i + mn2 + mn3 <= n) {
        int j = min(mx2, n - i - mn3);
        cout << i << ' ' << j << ' ' << n - i - j << endl;
        return 0;
    }
}