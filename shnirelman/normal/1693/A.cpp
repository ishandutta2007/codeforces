#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 3e6 + 13;
const int LOGN = 30;
const int A = 26;

/*

*/

void solve() {
    int n;
    cin >> n;

    vector<li> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int lst = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] != 0)
            lst = i;
    }

    if(lst == -1) {
        cout << "YES" << endl;
        return;
    }

    for(int i = 0; i < lst; i++)
        a[i]--;

    while(lst > 0) {
        if(a[lst] > 0) {
            cout << "NO" << endl;
            return;
        } else if(a[lst] < 0) {
            a[lst - 1] += a[lst] + 1;
            a[lst] = 0;
        }

        lst--;
    }

    cout << (a[lst] == 0 ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}