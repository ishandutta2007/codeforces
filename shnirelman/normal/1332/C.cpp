#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

const int N = 2e5 + 13;

int p[N], sz[N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

void unit(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return;

    if(sz[x] < sz[y])
        swap(x, y);

    p[y] = x;
    sz[x] += sz[y];
}

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    string s;
    cin >> s;

    for(int i = 0; i < k; i++) {
        for(int j = i; j < n; j += k)
            unit(i, j);
    }

    for(int i = 0; i < n; i++) {
        unit(i, n - i - 1);
    }

//    cout << "gfd" << endl;
//
    vector<map<char, int>> mp(n);
    for(int i  = 0; i < n; i++) {
        //getp(i);
        mp[getp(i)][s[i]]++;
    }
//cout << "gfd" << endl;
    int ans = 0;
    for(int i = 0; i < n; i++) {

        if(mp[i].empty())
            continue;

        int mx = 0;
        for(auto p : mp[i])
            mx = max(mx, p.s);

        ans += sz[i] - mx;
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}