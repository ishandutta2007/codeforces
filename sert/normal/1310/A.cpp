#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    map<int, vector<int>> costs;
    set<int> times;

    int n;
    cin >> n;
    vector<int> t(n);
    for (int &x : t) cin >> x;
    vector<int> c(n);
    for (int &x : c) cin >> x;
    for (int i = 0; i < n; i++) {
        costs[t[i]].push_back(c[i]);
        times.insert(t[i]);
    }

    long long ans = 0;
    long long sum = 0;
    int curT = *(times.begin());
    int maxT = *(times.rbegin());

    priority_queue<int> q;
    while (true) {
        for (int c : costs[curT]) {
            sum += c;
            // cout << "+ " << c << "\n";
            q.push(c);
        }
        if (!q.empty()) {
            // cout << "- " << q.top() << "\n";
            sum -= q.top();
            q.pop();
        }
        ans += sum;

        // cout << curT << " " << sum << " " << ans << "\n";

        if (q.empty()) {
            if (curT >= maxT) break;
            else curT = *times.upper_bound(curT);
        } else {
            curT++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 2;
    for (int i = 1; i < T; i++) solve();    
#endif
}