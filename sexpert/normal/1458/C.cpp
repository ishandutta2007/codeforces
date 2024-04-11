// mike fix your website smh
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1005;
int ans[MAX][MAX];

void solve() {
    vector<array<int, 3>> guys;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            guys.push_back({i, j, x});
        }

    array<int, 3> st = {0, 1, 2}, df = {0, 0, 0};
    string s;
    cin >> s;
    for(auto &c : s) {
        if(c == 'R')
            df[st[1]]++;
        if(c == 'L')
            df[st[1]]--;
        if(c == 'D')
            df[st[0]]++;
        if(c == 'U')
            df[st[0]]--;
        if(c == 'I')
            swap(st[1], st[2]);
        if(c == 'C')
            swap(st[0], st[2]);
    }
    auto tf = [&](auto &p) {
        for(int i = 0; i < 3; i++) {
            p[i] = ((p[i] + df[i]) % n + n) % n;
            if(p[i] == 0)
                p[i] = n;
        }
    };
    for(auto p : guys) {
        tf(p);
        int x = p[st[0]], y = p[st[1]], z = p[st[2]];
        ans[x][y] = z;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}