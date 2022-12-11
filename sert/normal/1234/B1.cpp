#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> q;
    int st = 0;

    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s.find(x) != s.end()) continue;
        s.insert(x);
        q.push_back(x);
        if ((int)s.size() > k) {
            s.erase(q[st++]);
        }
    }

    cout << s.size() << "\n";
    for (int i = (int)q.size() - 1; i >= st; i--) {
        cout << q[i] << " ";
    }
    cout << "\n";
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