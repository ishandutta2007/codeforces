#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
*/

void solve() {

}


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    int t = 1;
//    cin >> t;
//
//    while(t--) {
//        solve();
//    }

    int n, q;
    cin >> n >> q;

    int cnt = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i];
    }

    for(int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;

        if(t == 1) {
            x--;
            cnt -= a[x];
            a[x] = 1 - a[x];
            cnt += a[x];
        } else {
            cout << (x <= cnt ? 1 : 0) << endl;
        }
    }
}