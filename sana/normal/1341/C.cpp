#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int n;

int get_cnt(set< pair<int,int> >& s, int pos) {
    auto it = s.lower_bound({pos, 0});
    if (it == s.begin()) return 0;
    --it;

    if (it->first - it->second == pos) return -it->second;
    return 0;
}

int get_maxcnt(set< pair<int,int> >& s) {
    auto it = s.begin();
    if (it == s.end()) return 0;
    if (it->second - it->first == n) it++;
    if (it == s.end()) return 0;
    // cout << "max comes from " << -it->first << " " << it->second << "\n";
    return -it->first;
}

void erase(pair<int,int> rem, set< pair<int,int> >& ints_o, set< pair<int,int> >& ints) {
    ints_o.erase(rem);
    ints.erase({rem.second, rem.first});
}

void insert(pair<int,int> rem, set< pair<int,int> >& ints_o, set< pair<int,int> >& ints) {
    ints_o.insert(rem);
    ints.insert({rem.second, rem.first});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) {
        cin >> n;
        vector<int> p(n), inv(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            inv[p[i] - 1] = i;
        }

        set< pair<int,int> > ints;
        set< pair<int,int> > ints_o;
        bool good = true;

        for (int i = 0; i < n; i++) {
            int count = get_cnt(ints_o, inv[i]);
            int max_count = get_maxcnt(ints);

            // cout << count << " " << max_count << endl;

            if (count != max_count) {
                good = false;
                break;
            }

            ints.insert({-1, inv[i]});
            ints_o.insert({inv[i], -1});

            pair<int,int> cur = {inv[i], -1};

            auto nxt = ints_o.lower_bound({inv[i], -n-1000});
            ++nxt;
            if (nxt != ints_o.end() && nxt->first == inv[i]+1) {
                // cout << "merge right";

                pair<int,int> rem = *nxt;
                // cout << "erase " << rem.first << " " << rem.second << "\n";
                erase(rem, ints_o, ints);
                erase(cur, ints_o, ints);

                cur.second += rem.second;
                insert(cur, ints_o, ints);
            }

            auto prv = ints_o.lower_bound({inv[i], -n-1000});
            if (prv != ints_o.begin()) {
                --prv;

                // cout << "prv: " << prv->first << " " << prv->second << endl;
                if (prv->first - prv->second == inv[i]) {
                    // cout << "merge left";

                    pair<int, int> rem = *prv;
                    // cout << "erase " << rem.first << " " << rem.second << "\n";
                    erase(rem, ints_o, ints);
                    erase(cur, ints_o, ints);

                    cur.first = rem.first;
                    cur.second += rem.second;
                    // cout << "insert " << rem.first << " " << rem.second << "\n";
                    insert(cur, ints_o, ints);
                }
            }
        }

        if (good) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}