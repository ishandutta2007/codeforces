#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int M = 26;

void solve() {
    vector<set<int>> pos(M);
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.length(); i++) {
        pos[s[i] - 'a'].insert(i);
    }
    int m;
    cin >> m;
    while (m--) {
        int type;
        cin >> type;        
        if (type == 1) {
            int p;
            char ch;
            cin >> p >> ch;
            p--;
            pos[s[p] - 'a'].erase(p);
            pos[ch - 'a'].insert(p);
            s[p] = ch;
        } else {
            int ans = 0;
            int l, r;
            cin >> l >> r;
            l--;
            for (int i = 0; i < M; i++) {
                auto it = pos[i].lower_bound(l);
                if (it != pos[i].end() && *it < r) ans++;
            }
            cout << ans << "\n";
        }
    }
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