#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

using namespace std;
using li = long long;
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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    cin >> a;

    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur += a[i];
        int d = min(cur, 8);
        cur -= d;
        k -= d;
        if(k <= 0) {
            cout << i + 1;
            exit(0);
        }
    }
    cout << -1;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}