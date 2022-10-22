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
    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a;

    li s1 = 0, s2 = 0;
    li ans = -1e18;
    li mn = 0;
    for(int i = 0; i < n - 1; i++) {
        s1 += abs(a[i] - a[i + 1]) * (i % 2 == 0 ? 1 : -1);
        ans = max(ans, s1 - mn);
        mn = min(mn, s1);
//        cout << s1 << endl;
    }



    mn = 0;
    for(int i = 1; i < n - 1; i++) {
        s2 += abs(a[i] - a[i + 1]) * (i % 2 == 1 ? 1 : -1);
        ans = max(ans, s2 - mn);
        mn = min(mn, s2);
    }

    cout << ans;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}