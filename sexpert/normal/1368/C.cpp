#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    vector<pair<int, int>> sq;
    for(int i = 0; i <= k + 1; i++) {
        sq.push_back({i, i});
        if(i <= k) {
            sq.push_back({i + 1, i});
            sq.push_back({i, i + 1});
        }
    }

    cout << sq.size() << '\n';

    for(auto p : sq)
        cout << p.first << " " << p.second << '\n';
}