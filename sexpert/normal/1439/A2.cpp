#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using op = array<int, 6>;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<op> res;
    vector<vector<int>> gr(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            gr[i][j] = s[j] - '0';
    }

    auto fl = [&]() {
        auto &o = res.back();
        gr[o[0] - 1][o[1] - 1] ^= 1;
        gr[o[2] - 1][o[3] - 1] ^= 1;
        gr[o[4] - 1][o[5] - 1] ^= 1;
    };

    if(n % 2) {
        if(m % 2) {
            if(gr[n - 1][m - 1] == 1) {
                res.push_back({n, m, n - 1, m, n, m - 1});
                fl();
            }
        }
        for(int i = 0; i + 1 < m; i += 2) {
            if(gr[n - 1][i] == 1 && gr[n - 1][i + 1] == 0) {
                res.push_back({n, i + 1, n - 1, i + 1, n - 1, i + 2});
                fl();
            }
            else if(gr[n - 1][i] == 0 && gr[n - 1][i + 1] == 1) {
                res.push_back({n, i + 2, n - 1, i + 1, n - 1, i + 2});
                fl();
            }
            else if(gr[n - 1][i] == 1 && gr[n - 1][i + 1] == 1) {
                res.push_back({n, i + 1, n, i + 2, n - 1, i + 1});
                fl();
            }
        }
    }
    if(m % 2) {
        for(int j = 0; j + 1 < n; j += 2) {
            if(gr[j][m - 1] == 1 && gr[j + 1][m - 1] == 0) {
                res.push_back({j + 1, m, j + 1, m - 1, j + 2, m - 1});
                fl();
            }
            else if(gr[j][m - 1] == 0 && gr[j + 1][m - 1] == 1) {
                res.push_back({j + 2, m, j + 1, m - 1, j + 2, m - 1});
                fl();
            }
            else if(gr[j][m - 1] == 1 && gr[j + 1][m - 1] == 1) {
                res.push_back({j + 1, m, j + 2, m, j + 1, m - 1});
                fl();
            }
        }
    }

    vector<vector<int>> ops(16);
    for(int m1 = 0; m1 < 16; m1++) {
        if(__builtin_popcount(m1) != 3)
            continue;
        for(int m2 = 0; m2 < 16; m2++) {
            if(__builtin_popcount(m2) != 3)
                continue;
            for(int m3 = 0; m3 < 16; m3++) {
                if(__builtin_popcount(m3) != 3)
                    continue;
                ops[m1^m2^m3] = {m1, m2, m3};
                for(int m4 = 0; m4 < 16; m4++) {
                    if(__builtin_popcount(m4) != 3)
                        continue;
                    ops[m1^m2^m3^m4] = {m1, m2, m3, m4};
                }
            }
            ops[m1^m2] = {m1, m2};
        }
        ops[m1] = {m1};
    }

    /*for(int i = 0; i < 16; i++) {
        cout << i << '\n';
        for(auto &x : ops[i])
            cout << x << " ";
        cout << '\n';
    }*/

    for(int i = 0; i + 1 < n; i += 2) {
        for(int j = 0; j + 1 < m; j += 2) {
            int wa = gr[i][j] + 2*gr[i][j + 1] + 4*gr[i + 1][j] + 8*gr[i + 1][j + 1];
            for(auto &ms : ops[wa]) {
                //cout << ms << " ";
                int ptr = 0;
                op app;
                for(int b = 0; b < 4; b++)
                    if(ms & (1 << b)) {
                        if(b == 0) {
                            app[ptr] = i + 1;
                            app[ptr + 1] = j + 1;
                        }
                        if(b == 1) {
                            app[ptr] = i + 1;
                            app[ptr + 1] = j + 2;
                        }
                        if(b == 2) {
                            app[ptr] = i + 2;
                            app[ptr + 1] = j + 1;
                        }
                        if(b == 3) {
                            app[ptr] = i + 2;
                            app[ptr + 1] = j + 2;
                        }
                        ptr += 2;
                    }

                res.push_back(app);
            }
        }
    }

    cout << res.size() << '\n';
    for(auto &[a, b, c, d, e, f] : res)
        cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}