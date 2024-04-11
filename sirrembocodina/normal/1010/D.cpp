#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

vector<int> s[1000100];
int t[1000100];
int a[1000100];
int b[1000100];

void cnt(int v) {
    if (t[v] == -1) {
        return;
    }
    forn (i, s[v].size()) {
        cnt(s[v][i]);
    }
    if (t[v] == 0) {
        a[v] = a[s[v][0]] & a[s[v][1]];
    } else if (t[v] == 1) {
        a[v] = a[s[v][0]] | a[s[v][1]];
    } else if (t[v] == 2) {
        a[v] = a[s[v][0]] ^ a[s[v][1]];
    } else {
        a[v] = 1 - a[s[v][0]];
    }
}

void dfs(int v, int x = 2) {
    if (t[v] == -1) {
        if (x == 0) {
            b[v] = 0;
        } else if (x == 1) {
            b[v] = 1;
        } else if (x == 2) {
            b[v] = 1 - a[v];
        } else {
            b[v] = a[v];
        }
        return;
    }
    if (x == 0 || x == 1) {
        forn (i, s[v].size()) {
            dfs(s[v][i], x);
        }
        return;
    }
    if (t[v] == 0) {
        forn (i, 2) {
            int y = a[s[v][1 - i]];
            if (x == 2) {
                if (y == 0) {
                    dfs(s[v][i], 0);
                } else {
                    dfs(s[v][i], 2);
                }
            } else {
                if (y == 0) {
                    dfs(s[v][i], 1);
                } else {
                    dfs(s[v][i], 3);
                }
            }
        }
        return;
    }
    if (t[v] == 1) {
        forn (i, 2) {
            int y = a[s[v][1 - i]];
            if (x == 2) {
                if (y == 1) {
                    dfs(s[v][i], 1);
                } else {
                    dfs(s[v][i], 2);
                }
            } else {
                if (y == 1) {
                    dfs(s[v][i], 0);
                } else {
                    dfs(s[v][i], 3);
                }
            }
        }
        return;
    }
    if (t[v] == 2) {
        forn (i, 2) {
            int y = a[s[v][1 - i]];
            if (x == 2) {
                if (y == 1) {
                    dfs(s[v][i], 3);
                } else {
                    dfs(s[v][i], 2);
                }
            } else {
                if (y == 1) {
                    dfs(s[v][i], 2);
                } else {
                    dfs(s[v][i], 3);
                }
            }
        }
        return;
    }
    dfs(s[v][0], 5 - x);
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    forn (i, n) {
        string x;
        cin >> x;
        t[i] = -1;
        if (x[0] == 'A') {
            t[i] = 0;
        } else if (x[0] == 'O') {
            t[i] = 1;
        } else if (x[0] == 'X') {
            t[i] = 2;
        } else if (x[0] == 'N') {
            t[i] = 3;
        }
        if (t[i] == -1) {
            cin >> a[i];
        } else if (t[i] == 3) {
            s[i].resize(1);
            cin >> s[i][0];
            s[i][0]--;
        } else {
            s[i].resize(2);
            cin >> s[i][0] >> s[i][1];
            s[i][0]--;
            s[i][1]--;
        }
    }
    cnt(0);
    dfs(0);
    forn (i, n) {
        if (t[i] == -1) {
            cout << b[i];
        }
    }
    cout << endl;
    return 0;
}