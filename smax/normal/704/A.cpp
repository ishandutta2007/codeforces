#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q, id = 1, ret = 0;
    queue<int> app[300000];
    queue<pair<int, int>> total;
    cin >> n >> q;
    for (int i=0; i<q; i++) {
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            app[x-1].push(id);
            total.push(make_pair(x, id++));
            ret++;
        } else if (type == 2) {
            ret -= app[x-1].size();
            while (!app[x-1].empty()) app[x-1].pop();
        } else
            while (!total.empty() && total.front().second <= x) {
                auto p = total.front();
                total.pop();
                if (!app[p.first-1].empty() && app[p.first-1].front() == p.second) {
                    ret--;
                    app[p.first-1].pop();
                }
            }
        cout << ret << "\n";
    }

    return 0;
}