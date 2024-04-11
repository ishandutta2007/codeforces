#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

istream& operator >>(istream& cin, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cin >> a[i];
    return cin;
}

ostream& operator <<(ostream& cout, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    return cout;
}

const int M = 1e9 + 7;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> a(n, false);
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;

        x--;

        a[x] = true;
    }

    int cur = 0;

    if(a[cur]) {
        cout << cur + 1;
        exit(0);
    }

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        if(cur == x) {
            cur = y;
        } else if(cur == y) {
            cur = x;
        }

        if(a[cur]) {
            cout << cur + 1 << endl;
            exit(0);
        }
    }

    cout << cur + 1;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}