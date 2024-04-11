#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

void solve() {
    int l, r;
    cin >> l >> r;

    int n = r - l + 1;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

//    int k = 0;
//    while((1 << k) <= r)
//        k++;
//    k--;
    int k = 17;

//    int x = (a[0] >> k) << k;
    int x = 0;

    for(int i = k; i >= 0; i--) {
        vector<int> cnt(2, 0);
        for(int j = 0; j < n; j++) {
            cnt[(a[j] >> i) & 1]++;
        }

        if(cnt[1] > cnt[0])
            x |= (1 << i);
    }

    cout << x << endl;
//    cout << "res : ";
//    for(int y : a)
//        cout << (x ^ y) << ' ';
//    cout << endl;


//    if((1 << k) - 1 == r) {
//        cout << x << endl;
//
//    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}