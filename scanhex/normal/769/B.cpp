#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n - 1);
    int a0;
    cin >> a0;
    deque<int> out;
    for (int i = 0; i < a0; i++) {
        out.push_back(0);
    }
    for (int i = 1; i < n; i++) {
        cin >> a[i - 1].first;
        a[i - 1].second = i;
    }
    sort(a.rbegin(), a.rend());

    vector<pair<int, int>> ans;
    int it = 0;
    while (!out.empty() && it < a.size()) {
        int u = out.front();
        out.pop_front();
        ans.push_back({u, a[it].second});
        for (int j = 0; j < a[it].first; j++) {
            out.push_back(a[it].second);
        }
        it++;
    }

    if (ans.size() < n - 1) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
        }
    }

    return 0;
}