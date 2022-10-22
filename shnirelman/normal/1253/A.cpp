#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i <  n; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
        a[i] = b[i] - a[i];

    bool fl = false;
    bool fl1 = false;
    for(int i = 0; i < n; i++) {
        if(a[i] < 0) {
            cout << "NO" << endl;
            return;
        } else if(a[i] > 0) {
            if(fl1) {
                cout << "NO" << endl;
                return;
            }
            if(fl) {
                if(a[i - 1] != a[i]) {
                    cout << "NO" << endl;
                    return;
                }
            } else {
                fl = true;
            }
        } else {
            if(fl)
                fl1 = true;
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
          solve();
}