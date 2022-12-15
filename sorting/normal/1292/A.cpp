#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> queries(q);
    for(auto &query: queries){
        cin >> query.first >> query.second;
        query.first--;
        query.second--;
    }

    int cnt_blocked = 0;
    vector<array<bool, 2>> table(n, {0, 0});

    for(const auto &[y, x]: queries){
        int cnt = 0;
        if(x != 0)
            cnt += table[x - 1][!y];
        cnt += table[x][!y];
        if(x != n - 1)
            cnt += table[x + 1][!y];

        cnt_blocked += cnt * (table[x][y] ? -1 : 1);
        table[x][y] = !table[x][y];

        cout << (cnt_blocked ? "No" : "Yes") << "\n";
    }
}