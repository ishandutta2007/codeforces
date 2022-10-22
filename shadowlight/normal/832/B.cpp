#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-8;
const int MAXN = 1e6 + 7;
const int Q = 31;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //  freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    vector <bool> good(Q, 0);
    for (char c : s) {
        good[c - 'a'] = true;
    }
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1;
        cin >> s1;
        int sz = s1.size() - s.size() + 1;
        if (sz < 0) {
            cout << "NO\n";
            continue;
        }
        int j = 0;
        bool fl = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                if (j >= s1.size()) {
                    fl = 1;
                    break;
                }
                if (!good[s1[j] - 'a']) {
                    fl = 1;
                    break;
                }
            } else if (s[i] == '*') {
                for (int k = 0; k < sz; k++) {
                    if (good[s1[j + k] - 'a']) {
                        fl = 1;
                        break;
                    }
                }
                j += sz;
                if (fl) break;
                continue;
            } else if (s1[j] != s[i]) {
                if (j >= s1.size()) {
                    fl = 1;
                    break;
                }
                fl = 1;
                break;
            }
            j++;
        }
        if (fl || j != s1.size()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}