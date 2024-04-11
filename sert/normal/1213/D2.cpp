#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int N = (int)2e5 + 41;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> steps(N);
    while (n--) {
        int x;
        cin >> x;
        steps[x].push_back(0);
        for (int i = 1; x > 0; i++) {
            steps[x /= 2].push_back(i);
        }
    }
    int ans = -1;
    for (int i = 0; i < N; i++) {
        if ((int)steps[i].size() < k) continue;        
        sort(all(steps[i]));
        int sum = accumulate(steps[i].begin(), steps[i].begin() + k, 0);
        if (ans == -1 || sum < ans) ans = sum;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 3;
    for (int i = 1; i < T; i++) solve();    
#endif
}