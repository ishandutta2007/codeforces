#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244853;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int siz = 0;
    vector<int> anss(n + 1);
    set<int> indus;
    for (int x = 1; x <= n; x++) indus.insert(x);
    vector<pair<char, int>> op;
    for (int i = 0; i < 2 * n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            siz++;
            op.pb({'+', -1});
        } else {
            int x;
            cin >> x;
            op.pb({'-', x});
            if (indus.upper_bound(siz) == indus.begin()) {
                cout << "NO\n";
                exit(0);
            }
            int husiz = *(--indus.upper_bound(siz));
            anss[husiz] = x;
            indus.erase(husiz);
        }
    }
    int kek = 1;
    set<int> omegalol;
    for (auto p : op) {
        if (p.first == '+') {
            omegalol.insert(anss[kek++]);
        } else {
            if (p.second != *omegalol.begin()) {
                cout << "NO\n";
                exit(0);
            }
            omegalol.erase(omegalol.begin());
        }
    }
    cout << "YES\n";
    for (int x = 1; x <= n; x++) cout << anss[x] << ' ';
}