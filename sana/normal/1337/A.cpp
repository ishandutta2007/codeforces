#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << b <<  ' ' << c << ' ' << c << '\n';
    }

    return 0;
}