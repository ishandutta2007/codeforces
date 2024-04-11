#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, L, R;
vector<pair<int, int>> req;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        req.emplace_back(L, R);
    }

    sort(req.begin(), req.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    int end = -2e9, ans = 0;

    for (int i = 0; i < N; i++) {
        if (req[i].first <= end) continue;
        end = req[i].second;
        ans++;
    }

    cout << ans << "\n";
}