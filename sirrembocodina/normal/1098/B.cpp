#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

vector<vector<int> > a, b, best;
int res = -1;

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    a.resize(n);
    forn (i, n) {
        string s;
        cin >> s;
        a[i].resize(m);
        forn (j, m) {
            if (s[j] == 'A') {
                a[i][j] = 0;
            } else if (s[j] == 'G') {
                a[i][j] = 1;
            } else if (s[j] == 'C') {
                a[i][j] = 2;
            } else if (s[j] == 'T') {
                a[i][j] = 3;
            }
        }
    }
    b = a;
    forn (x, 4) {
        forn (y, x) {
            forn (z, 4) {
                forn (t, z) {
                    if (x == z || x == t || y == z || y == t) {
                        continue;
                    }
                    int sum = 0;
                    forn (i, n) {
                        int cur1 = 0, cur2 = 0;
                        vector<int> bb1(m), bb2(m);
                        if (i % 2) {
                            forn (j, m) {
                                bb1[j] = j % 2 ? x : y;
                                bb2[j] = j % 2 ? y : x;
                            }
                        } else {
                            forn (j, m) {
                                bb1[j] = j % 2 ? z : t;
                                bb2[j] = j % 2 ? t : z;
                            }
                        }
                        forn (j, m) {
                            if (a[i][j] == bb1[j]) {
                                ++cur1;
                            }
                            if (a[i][j] == bb2[j]) {
                                ++cur2;
                            }
                        }
                        if (cur1 > cur2) {
                            sum += cur1;
                            b[i] = bb1;
                        } else {
                            sum += cur2;
                            b[i] = bb2;
                        }
                    }
                    if (sum > res) {
                        res = sum;
                        best = b;
                    }
                    sum = 0;
                    forn (j, m) {
                        int cur1 = 0, cur2 = 0;
                        vector<int> bb1(n), bb2(n);
                        if (j % 2) {
                            forn (i, n) {
                                bb1[i] = i % 2 ? x : y;
                                bb2[i] = i % 2 ? y : x;
                            }
                        } else {
                            forn (i, n) {
                                bb1[i] = i % 2 ? z : t;
                                bb2[i] = i % 2 ? t : z;
                            }
                        }
                        forn (i, n) {
                            if (a[i][j] == bb1[i]) {
                                ++cur1;
                            }
                            if (a[i][j] == bb2[i]) {
                                ++cur2;
                            }
                        }
                        if (cur1 > cur2) {
                            sum += cur1;
                            forn (i, n) {
                                b[i][j] = bb1[i];
                            }
                        } else {
                            sum += cur2;
                            forn (i, n) {
                                b[i][j] = bb2[i];
                            }
                        }
                    }
                    if (sum > res) {
                        res = sum;
                        best = b;
                    }
                }
            }
        }
    }
    forn (i, n) {
        forn (j, m) {
            if (best[i][j] == 0) {
                cout << 'A';
            } else if (best[i][j] == 1) {
                cout << 'G';
            } else if (best[i][j] == 2) {
                cout << 'C';
            } else if (best[i][j] == 3) {
                cout << 'T';
            }
        }
        cout << endl;
    }
    return 0;
}