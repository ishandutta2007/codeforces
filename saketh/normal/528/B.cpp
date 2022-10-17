#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, X, W;
    cin >> N;

    vector<pair<int, int>> intv;

    for (int i = 0; i < N; i++) {
        cin >> X >> W;
        intv.emplace_back(X - W, X + W);
    }

    int edge = -2e9;

    sort(intv.begin(), intv.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    int ans = 0;

    for (auto p : intv) {
        if (p.first < edge) continue;
        ans++;
        edge = p.second;
    }

    cout << ans << "\n";
}