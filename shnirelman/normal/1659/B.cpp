#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> res(n, k);

    int cur = k;
    for(int i = 0; cur > 0 && i < n; i++) {
        if((s[i] - '0' + res[i]) % 2 == 0) {
            res[i]--;
            cur--;
        }
    }

    res[0] -= cur - cur % 2;
    cur %= 2;

    if(cur) {
        res[n - 1]--;
    }

    for(int i = 0; i < n; i++)
        cout << (s[i] - '0' + res[i]) % 2;
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << k - res[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}