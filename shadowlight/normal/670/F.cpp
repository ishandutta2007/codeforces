#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    string s, t;
    cin >> s >> t;
    if (s.size() == 2 && t == "0") {
        cout << "0";
        return 0;
    }
    vector <int> cnt(10, 0);
    for (char c : s) {
        cnt[c - '0']++;
    }
    for (char c : t) {
        cnt[c - '0']--;
    }
    int n = s.size(), m = t.size();
    int sz = 0;
    for (int i = 1; i <= 7; i++) {
        sz = s.size() - i;
        int x = sz;
        int cnt = 0;
        while (x) {
            cnt++;
            x /= 10;
        }
        if (cnt == i) {
            break;
        }
    }
    while (sz) {
        cnt[sz % 10]--;
        sz /= 10;
    }
    int stop = t[0] - '0';
    int id = 1;
    while (id < m && t[id] == t[id - 1]) id++;
    if (id != m && t[id - 1] > t[id]) {
        stop--;
    }
    bool ex = 0;
    string res = "";
    if (!stop && t[0] != '0') {
        int zero = 1;
        while (id + 1 < m && t[id] == t[id + 1]) {
            zero++;
            id++;
        }
        if (cnt[1] && zero <= cnt[0]) {
            res += "1";
            cnt[1]--;
            for (int i = 0; i < cnt[0]; i++) {
                res += "0";
            }
            cnt[0] = 0;
        }
    }
    int w = -1;
    for (int i = 1; i < 10; i++) {
        if (cnt[i]) {
            w = i;
            break;
        }
    }
    if (t[0] == '0') {
        res += (char) (w + '0');
        cnt[w]--;
    } else {
        if (!ex && (w == -1 || w > stop)) {
            res += t;
            ex = true;
        } else {
            res += (char) (w + '0');
            cnt[w]--;
        }
    }
    for (int i = 0; i <= stop; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            res += (char) (i + '0');
        }
    }
    if (!ex) {
        res += t;
    }
    for (int i = stop + 1; i < 10; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            res += (char) (i + '0');
        }
    }
    cout << res;
}