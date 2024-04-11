#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

string pref = "", suf = "";

vector <bool> tp;
vector <string> all;

int n;

bool solve() {
    tp.clear();
    tp.resize(n, false);
    vector <int> cnta(n, 0), cntb(n, 0);
    for (int i = 0; i < 2 * n - 2; i++) {
        int sz = all[i].size();
        if (!cnta[sz] && all[i] == pref.substr(0, sz)) {
            cnta[sz]++;
            tp[i] = 0;
        } else if (!cntb[sz] && all[i] == suf.substr(suf.size() - sz, sz)) {
            cntb[sz]++;
            tp[i] = 1;
        } else {
            return false;
        }
    }
    return pref.substr(1, n - 2) == suf.substr(0, n - 2);
}

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
    cin >> n;
    tp.resize(n);
    vector <string> a;
    for (int i = 0; i < 2 * n - 2; i++) {
        string s;
        cin >> s;
        if (s.size() == n - 1) {
            a.push_back(s);
        }
        all.push_back(s);
    }
    suf = a[0], pref = a[1];
    if (!solve()) {
        swap(suf, pref);
        solve();
    }
    for (int i = 0; i < 2 * n - 2; i++) {
        cout << (tp[i] ? "S" : "P");
    }
}