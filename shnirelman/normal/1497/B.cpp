#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 20;
const int A = 27;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i] % m]++;
    }

    int ans = mp.count(0);
    for(int i = 1; i < m; i++) {
        if(mp[i] == 0)
            continue;
        int x = mp[i];
        int y = mp[m - i];

        if(x < y)
            swap(x, y);

        ans += max(1, x - y);

//        cout << ans << ' ' << i << ' ' << x << ' ' << y << endl;

        mp[i] = mp[m - i] = 0;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}