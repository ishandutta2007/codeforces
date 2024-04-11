#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

void solve() {
    int n, m;
    cin >> n >> m;

    int l = m, r = m;
    int t = 0;

    bool ans = true;
    for(int i = 0; i < n; i++) {
        int qt, ql, qr;
        cin >> qt >> ql >> qr;
//        cout <<"lr " << l << ' ' << r << endl;

        int d = qt - t;
        t = qt;
        l -= d;
        r += d;
//cout <<"lr " << l << ' ' << r << endl;
        l = max(l, ql);
        r = min(r, qr);

        if(r < l) {
            ans = false;
        }
    }

    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);



    int t;
    cin >> t;
    while(t--)
        solve();
}