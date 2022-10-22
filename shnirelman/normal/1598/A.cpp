#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    if(s1[0] == '1' || s2[n - 1] == '1') {
        cout << "NO" << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(s1[i] == '1' && s2[i] == '1') {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}