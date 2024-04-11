#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#else
    //    freopen("lupa.in","r",stdin);
    //    freopen("pupa.out","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10);
    cout << fixed;
    int t;
    cin >> t;
    while (--t >= 0) {
        int a1, a2, a3;
        int c1, c2, c3, c4, c5;
        cin >> a1 >> a2 >> a3 >> c1 >> c2 >> c3 >> c4 >> c5;
        if (a1 < c1 || a2 < c2) {
            cout << "NO\n";
            continue;
        }
        a1 -= c1;
        a2 -= c2;
        c4 -= a1;
        c5 -= a2;
        c4 = max(0, c4);
        c5 = max(0, c5);
        if (a3 >= c3 + c4 + c5) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}