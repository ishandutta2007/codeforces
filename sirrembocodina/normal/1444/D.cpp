#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

bool divide(vector<int>& a) {
    int n = a.size();
    int sum = 0;
    forn (i, n) {
        sum += a[i];
    }
    if (sum % 2) {
        return false;
    }
    sum /= 2;
    vector<int> p(sum + 1, -2);
    p[0] = -1;
    int cur_sum = 0;
    for (int i = 0; i < n; i++) {
        int mx = min((int)(p.size()) - a[i], cur_sum + 1);
        for (int j = mx - 1; j >= 0; j--) {
            if (p[j] != -2 && p[j + a[i]] == -2) {
                p[j + a[i]] = i;
            }
        }
        cur_sum += a[i];
    }
    if (p[sum] == -2) {
        return false;
    }
    while (sum) {
        //cerr << sum << endl;
        a[p[sum]] *= -1;
        sum += a[p[sum]];
    }
    return true;
}

inline int sgn(int a) {
    return a < 0 ? -1 : 1;
}

bool cmp1(int a, int b) {
    if (sgn(a) != sgn(b)) {
        return sgn(a) > sgn(b);
    }
    return abs(a) > abs(b);
}

bool cmp2(int a, int b) {
    if (sgn(a) != sgn(b)) {
        return sgn(a) > sgn(b);
    }
    return abs(a) < abs(b);
}

bool cmp3(int a, int b) {
    if (sgn(a) != sgn(b)) {
        return sgn(a) < sgn(b);
    }
    return abs(a) > abs(b);
}

bool cmp4(int a, int b) {
    if (sgn(a) != sgn(b)) {
        return sgn(a) < sgn(b);
    }
    return abs(a) < abs(b);
}

bool check(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<int> l(500100, -2e18), r(500100, -2e18);
    vector<int> l2(500100, -2e18), r2(500100, -2e18);
    vector<int> w(500100, -2e18 + 1e3), v(500100, -2e18 + 1e3);
    vector<bool> we(500100), ve(500100);
    int x = 250005, y = 250005;
    forn (i, n) {
        if (a[i] > 0) {
            we[x] = true;
            forn (j, a[i] + 1) {
                w[x] = y;
                x++;
            }
            x--;
            we[x] = true;
        } else {
            ve[x] = true;
            forn (j, -a[i] + 1) {
                v[x] = y;
                x--;
            }
            x++;
            ve[x] = true;
        }
        if (l[x] == -2e18) {
            l[x] = y;
        } else {
            l2[x] = y;
        }
        y += b[i];
        if (r[x] == -2e18) {
            r[x] = y;
        } else {
            r2[x] = y;
        }
        if (l[x] > r[x]) {
            swap(l[x], r[x]);
        }
    }
    bool ok = true;
    forn (i, l.size()) {
        if (l[i] < w[i] && w[i] < r[i]) {
            ok = false;
        }
        if (l[i] < v[i] && v[i] < r[i]) {
            ok = false;
        }
        if ((l[i] == w[i] || w[i] == r[i]) && !we[i]) {
            ok = false;
        }
        if ((l[i] == v[i] || v[i] == r[i]) && !ve[i]) {
            ok = false;
        }
        if (l2[i] < w[i] && w[i] < r2[i]) {
            ok = false;
        }
        if (l2[i] < v[i] && v[i] < r2[i]) {
            ok = false;
        }
        if ((l2[i] == w[i] || w[i] == r2[i]) && !we[i]) {
            ok = false;
        }
        if ((l2[i] == v[i] || v[i] == r2[i]) && !ve[i]) {
            ok = false;
        }
    }
    if (ok) {
        cout << "Yes" << endl;
        x = y = 0;
        forn (i, n) {
            cout << x << " " << y << endl;
            x += a[i];
            cout << x << " " << y << endl;
            y += b[i];
        }
        return true;
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn (i, n) {
            cin >> a[i];
        }
        int tmp;
        cin >> tmp;
        vector<int> b(tmp);
        forn (i, tmp) {
            cin >> b[i];
        }
        if (n != tmp || !divide(a) || !divide(b)) {
            cout << "No" << endl;
            continue;
        }
        bool ok = false;
        forn (k, 2) {
        forn (i, 4) {
            if (i == 0) {
                sort(a.begin(), a.end(), cmp4);
            } else if (i == 1) {
                sort(a.begin(), a.end(), cmp1);
            } else if (i == 2) {
                sort(a.begin(), a.end(), cmp2);
            } else {
                sort(a.begin(), a.end(), cmp3);
            }
            forn (j, 4) {
                if (j == 0) {
                    sort(b.begin(), b.end(), cmp4);
                } else if (j == 1) {
                    sort(b.begin(), b.end(), cmp1);
                } else if (j == 2) {
                    sort(b.begin(), b.end(), cmp2);
                } else {
                    sort(b.begin(), b.end(), cmp3);
                }
                if (check(a, b)) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        if (ok) {
            break;
        }
        forn (i, n) {
            a[i] *= -1;
        }
    }
        if (!ok) {
            cout << "No" << endl;
            continue;
        }
    }
}