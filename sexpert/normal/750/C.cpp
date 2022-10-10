#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int lbnd = -INF, ubnd = INF;
    int n, delta = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int rat, div;
        cin >> rat >> div;
        if(div == 1)
            lbnd = max(lbnd, 1900 - delta);
        else
            ubnd = min(ubnd, 1899 - delta);
        delta += rat;
    }
    if(lbnd > ubnd) {
        cout << "Impossible\n";
        return 0;
    }
    if(ubnd == INF) {
        cout << "Infinity\n";
        return 0;
    }
    cout << ubnd + delta << endl;
}