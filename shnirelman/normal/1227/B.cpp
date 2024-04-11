#include <bits/stdc++.h>

#define x first
#define y second

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using li = long long;
using ld = long double;

const int M = 1e9 + 7;
//const li INF = 1e18;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n), a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0 && a[i] < a[i - 1]) {
            cout << -1 << endl;
            return;
        }
    }

    p[0] = a[0];
    //vector<bool> b(n + 1, false);
    //b[p[0]] = true;
    set<int> s;
    for(int i = 1; i <= n; i++)
        s.insert(i);
    s.erase(p[0]);

    for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1]) {
            p[i] = *s.begin();
            s.erase(s.begin());
            if(p[i] > a[i]) {
                cout << -1 << endl;
                return;
            }
        } else {
            p[i] = a[i];
            if(s.count(a[i]) == 0) {
                cout << -1 << endl;
                return;
            }
            s.erase(p[i]);
        }
    }
    for(int i = 0; i < n; i++)
        cout << p[i] << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>> t;
    while(t--)
        solve();
}