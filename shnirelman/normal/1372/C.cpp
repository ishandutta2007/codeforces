#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
1
4 2
9 12 12 6
2
4 5
3
111 11 11
*/


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    bool fl1 = false, fl2 = false;
    for(int i = 0; i < n; i++) {
        if(a[i] != i) {
            if(fl2) {
                cout << 2 << endl;
                return;
            } else {
                fl1 = true;
            }
        } else if(fl1) {
            fl2 = true;
        }
    }

    cout << fl1 << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}