#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int Q = 31;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, k;
    cin >> k >> n;
    vector <string> a(k - 1);
    string s;
    cin >> s;
    vector <vector <int> > pos(k - 1);
    vector <bool> good(k - 1, false);
    for (int i = 1; i < k; i++) {
        string s1;
        cin >> a[i - 1];
        vector <int> cnt(Q, 0);
        s1 = a[i - 1];
        for (char c : s1) {
            cnt[c - 'a']++;
        }
        for (int j = 0; j < Q; j++) {
            if (cnt[j] >= 2) {
                good[i - 1] = true;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (s[j] != s1[j]) {
                pos[i - 1].push_back(j);
            }
            if (pos[i - 1].size() > 4) {
                cout << -1;
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(s[i], s[j]);
            //cout << "? " << s << "\n";
//            if (s != "kbub") {
//                swap(s[i], s[j]);
//                continue;
//            }
            bool can = true;
            for (int p = 0; p < k - 1; p++) {
                auto mas = pos[p];
                int fl1 = 1, fl2 = 1;
                vector <int> bad;
                for (int x : mas) {
                    if (x == i) {
                        fl1 = 0;
                    }
                    if (x == j) {
                        fl2 = 0;
                    }
                    if (s[x] != a[p][x]) {
                        bad.push_back(x);
                    }
                }
//                if (!fl1) {
//                    mas.push_back(i);
//                }
//                if (!fl2) {
//                    mas.push_back(j);
//                }
                //cout << (int) mas.size() << "\n";
                if (mas.size() + fl1 + fl2 > 4) {
                    can = false;
                    break;
                }
//                for (int x : mas) {
//                    if (s[x] != a[p][x]) {
//                        bad.push_back(x);
//                    }
//                }
                if (fl1 && s[i] != a[p][i]) {
                    bad.push_back(i);
                }
                if (fl2 && s[j] != a[p][j]) {
                    bad.push_back(j);
                }
                if (!bad.size() && good[p]) {
                    continue;
                }
                if (bad.size() != 2) {
                    can = false;
                    break;
                }
                if (s[bad[0]] != a[p][bad[1]] || s[bad[1]] != a[p][bad[0]]) {
                    can = false;
                    break;
                }
            }
            if (can) {
                cout << s;
                return 0;
            }
            swap(s[i], s[j]);
        }
    }
    cout << -1;
    return 0;
}