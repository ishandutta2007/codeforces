#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
//const int M = 1e5 + 13;
const int A = 213;

/*
1
5
1 2 1 2 3
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> cnt(31, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < 30; j++) {
            if(a[i] & (1 << j))
                cnt[j]++;
        }
    }

    int g = 0;
    for(int i = 0; i < cnt.size(); i++)
        g = __gcd(g, cnt[i]);

    for(int i = 1; i <= n; i++) {
        if(g % i == 0)
            cout << i << ' ';
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}