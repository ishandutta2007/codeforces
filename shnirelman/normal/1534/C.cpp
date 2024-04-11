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

    vector<int> a(n), b(n), wh(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        wh[a[i]] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    int cnt = 1;
    vector<bool> used(n, false);
    for(int i = 0; i < n; i++) {
        if(used[i])
            continue;

        int j = i;
        while(!used[j]) {
            used[j] = true;
            j = wh[b[j]];
        }

        cnt = (cnt * 2ll) % M;
    }

    cout << cnt << endl;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}