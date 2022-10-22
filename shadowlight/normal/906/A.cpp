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
    int n;
    cin >> n;
    vector <bool> can(26, true);
    int cnt = 26;
    int res = 0;
    bool fl = false;
    for (int i = 0; i < n - 1; i++) {
        char c;
        cin >> c;
        if (fl) {
            string s;
            cin >> s;
            if (c != '.') {
                res++;
            }
            continue;
        }
        if (c == '?') {
            char x;
            cin >> x;
            if (can[x - 'a']) {
                can[x - 'a'] = false;
                cnt--;
            }
        } else {
            string s;
            cin >> s;
            if (c == '!') {
                vector <bool> exist(26, 0);
                for (char c : s) {
                    exist[c - 'a'] = 1;
                }
                for (int i = 0; i < 26; i++) {
                    if (!exist[i] && can[i]) {
                        can[i] = false;
                        cnt--;
                    }
                }
            } else {
                for (char c : s) {
                    if (can[c - 'a']) {
                        can[c - 'a'] = false;
                        cnt--;
                    }
                }
            }
        }
        if (cnt == 1) {
            fl = 1;
        }
    }
    cout << res;
}