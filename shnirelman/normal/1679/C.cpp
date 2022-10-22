#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int K = 9;
const int M = 2e6 + 9;
const int LOGN = 20;

void solve() {
    int n, q;
    cin >> n >> q;

    map<int, int> row, col;
    set<int> r, c;
    for(int i = 0; i <= n; i++) {
        r.insert(i);
        c.insert(i);
    }

    for(int i = 0; i < q; i++) {
        int tp;
        cin >> tp;

        if(tp == 1) {
            int x, y;
            cin >> x >> y;

            x--;
            y--;

            row[x]++;
            col[y]++;

            r.erase(x);
            c.erase(y);
        } else if(tp == 2) {
            int x, y;
            cin >> x >> y;

            x--;
            y--;

            if(--row[x] == 0)
                r.insert(x);
            if(--col[y] == 0)
                c.insert(y);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            x1--;
            y1--;

//            auto it = r.lower_bound(x1);
            if(*r.lower_bound(x1) >= x2 || *c.lower_bound(y1) >= y2)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}