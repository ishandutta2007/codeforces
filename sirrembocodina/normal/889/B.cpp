#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int mod = 1000000007;

int nxt[26];
int pr[26];
bool used[26];
bool was[26];
string t = "";

void dfs(int c) {
    if (used[c]) {
        cout << "NO\n";
        exit(0);
    }
    t += c + 'a';
    used[c] = true;
    if (nxt[c] != -1) {
        dfs(nxt[c]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    forn (i, 26) {
        nxt[i] = -1;
        pr[i] = -1;
    }
    forn (i, n) {
        cin >> s[i];
        forn (j, s[i].size()) {
            forn (k, j) {
                if (s[i][j] == s[i][k]) {
                    cout << "NO\n";
                    return 0;
                }
            }
            was[s[i][j] - 'a'] = true;
        }
        forn (j, s[i].size() - 1) {
            int c1 = s[i][j] - 'a';
            int c2 = s[i][j + 1] - 'a';
//            cerr << c1 << " " << c2 << endl;
            if (nxt[c1] != -1 && nxt[c1] != c2) {
                cout << "NO\n";
                return 0;
            }
            nxt[c1] = c2;
            if (pr[c2] != -1 && pr[c2] != c1) {
                cout << "NO\n";
                return 0;
            }
            pr[c2] = c1;
        }
    }
    forn (i, 26) {
        if (was[i] && !used[i] && pr[i] == -1) {
            dfs(i);
        }
    }
    forn (i, 26) {
        if (was[i] && !used[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << t << endl;
    return 0;
}