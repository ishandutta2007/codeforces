#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;
 
template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif
 
void run();
 
signed main() {
    // UseFiles("shelves");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}


vector<vector<int>> gen_table(const vector<int> &a) {
    int n = len(a);
    vector<vector<int>> fld(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fld[i][j] = a[i] * a[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        fld[i][i] = 0;
    }
    return fld;
}

int sqrt(int n) {
    int l = -1, r = 1e9;
    while (r - l > 1) {
        int c = (r + l) >> 1;
        if (c * c >= n) {
            r = c;
        } else {
            l = c;
        }
    }
    return r;
}

void run() {
    int n;
    cin >> n;
    vector<vector<int>> fld(n, vector<int>(n));
    for (auto &l : fld) {
        for (auto &x : l) {
            cin >> x;
        }
    }
    int g = 0;
    for (auto &x : fld[0]) {
        g = __gcd(g, x);
    }
    vector<int> a(fld[0]);
    for (auto &x : a) {
        x /= g;
    }
    a[0] = g;
    int ratio = fld[1][2] / (a[1] * a[2]);
    int s = sqrt(ratio);
    a[0] /= s;
    for (auto &x : a) {
        x *= s;
    }
    a[0] /= s;
    for (auto &x : a) {
        cout << x << " ";
    }
    cout << endl;
}