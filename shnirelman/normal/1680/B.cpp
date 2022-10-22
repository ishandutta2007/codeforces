#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'R') {
                bool fl = false;
                for(int x = 0; x < n; x++) {
                    for(int y = 0; y < m; y++) if(a[x][y] == 'R') {
                        if(x < i || y < j)
                            fl = true;
                    }
                }

                if(!fl) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }

    cout << "NO\n";
}

int main() {

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}