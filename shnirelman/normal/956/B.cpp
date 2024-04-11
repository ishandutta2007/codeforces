#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int r = 0;


    ld ans = -1;
    for(int i = 0; i < n; i++) {
        while(r < n && a[i] + x >= a[r])
            r++;
//        cout << i << ' ' << r << endl;
        if(i + 1 >= r - 1)
            continue;
        ans = max(ans, ld(a[r - 1] - a[i + 1]) / (a[r - 1] - a[i]));
    }

    if(ans < 0)
        cout << -1 << endl;
    else
        cout << setprecision(20) << fixed << ans << endl;
}