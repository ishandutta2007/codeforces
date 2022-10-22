#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector <pair <int, int> > a;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        a.push_back({x, i + 1});
    }
    sort(a.rbegin(), a.rend());
    int now = 0;
    queue <pair <int, int> > q;
    q.push({m, 1});
    vector <pair <int, int> > ans;
    while (now < n - 1 && !q.empty()) {
        auto p = q.front();
        q.pop();
        int v = p.second, x = p.first;
        for (int i = 0; i < x; i++) {
            if (now >= n - 1) break;
            q.push(a[now]);
            ans.push_back({v, a[now].second});
            now++;
        }
    }
    if (now < n - 1) {
        cout << -1;
        return 0;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}