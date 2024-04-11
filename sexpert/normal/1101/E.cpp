#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int mw = 0, mh = 0, n;
    cin >> n;
    while(n--) {
        int w, h;
        char c;
        cin >> c >> h >> w;
        if(w < h)
            swap(w, h);
        if(c == '+') {
            mw = max(mw, w);
            mh = max(mh, h);
        }
        else
            cout << ((mw <= w && mh <= h) ? "YES\n" : "NO\n");
    }
}