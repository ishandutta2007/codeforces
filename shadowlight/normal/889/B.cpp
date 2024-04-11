#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;
const int Q = 31;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    vector <int> nxt(Q, -1);
    vector <bool> haveP(Q, false);
    vector <bool> exist(Q, false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector <int> cnt(Q, 0);
        cnt[s[0] - 'a']++;
        exist[s[0] - 'a'] = true;
        for (int i = 1; i < (int) s.size(); i++) {
            int c = s[i - 1] - 'a', c1 = s[i] - 'a';
            if (nxt[c] != -1 && nxt[c] != c1) {
                cout << "NO\n";
                return 0;
            }
            nxt[c] = c1;
            exist[c1] = true;
            haveP[c1] = true;
            cnt[c1]++;
            if (cnt[c1] > 1) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    int all = 0;
    for (int i = 0; i < Q; i++) {
        if (exist[i]) {
            all++;
        }
    }
    vector <int> used(Q, 0);
    string res = "";
    for (int i = 0; i < Q; i++) {
        if (haveP[i] || !exist[i]) continue;
        int now = i;
        while (!used[now] && nxt[now] != -1) {
            used[now] = 1;
            res += (char) (now + 'a');
            now = nxt[now];
        }
        if (used[now]) {
            cout << "NO\n";
            return 0;
        }
        used[now] = 1;
        res += (char) (now + 'a');
    }
    if (res.size() != all) {
        cout << "NO\n";
        return 0;
    }
    cout << res;
}