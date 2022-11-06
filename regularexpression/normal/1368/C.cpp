#include<bits/stdc++.h>
using namespace std;

#define int long long 

vector<pair<int, int>> ans;

void add_cycle(int x, int y) {
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (i != 1 || j != 1)
                ans.emplace_back(x + i, y + j);
        }
    }
}

void add2(int x, int y) {
    ans.emplace_back(x + 2, y + 3);
    ans.emplace_back(x + 3, y + 2);
}

void add3(int x, int y) {
    add2(x, y);
    ans.emplace_back(x + 3, y + 3);
}

int tb[1000][1000];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x = 0, y = 0;
    add_cycle(x, y);
    while (n >= 2) {
        n -= 2;
        add2(x, y);
        x += 3;
        y += 3;
        add_cycle(x, y);
    }
    if (n) {
        add3(x, y);
    }
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i.first << " " << i.second << '\n';
    return 0;
}