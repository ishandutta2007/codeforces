#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e5;

void solve() {
    int n;
    cin >> n;
    int hmin = -INF, hmax = INF, vmin = -INF, vmax = INF;

    for(int i = 0; i < n; i++) {
        int x, y, a, b, c, d;
        cin >> x >> y >> a >> b >> c >> d;
        if(!a)
            hmin = max(hmin, x);
        if(!c)
            hmax = min(hmax, x);
        if(!b)
            vmax = min(vmax, y);
        if(!d)
            vmin = max(vmin, y);
    } 

    if(hmin <= hmax && vmin <= vmax)
        cout << "1 " << hmin << " " << vmin << '\n';
    else
        cout << "0\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}