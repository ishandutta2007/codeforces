#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define int ll

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e9;

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
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

vector<int> color;
vector<vector<int>> pref;
int n;

int calc_score(int pos1, int pos2) {
    assert(pos2 >= pos1);
    int sm = pos1 - pref[0][pos1];
    sm += (n - pos2) - (pref[2].back() - pref[2][pos2]);
    sm += (pos2 - pos1) - (pref[1][pos2] - pref[1][pos1]);
    return sm;
}

vector<int> best_score;

void calc_best_score(int l, int r, int a, int b) {
    if (l > r) {
        return;
    }
    int m = (l + r) >> 1;
    int pos = 0;
    for (int i = a; i <= min(b, m); ++i) {
        int s = calc_score(i, m);
        if (cmin(best_score[m], s)) {
            pos = i;
        }
    }
    calc_best_score(l, m - 1, a, pos);
    calc_best_score(m + 1, r, pos, b);
}

void run() {
    int a, b, c;
    cin >> a >> b >> c;
    n = a + b + c;
    color.resize(n);
    for (int i = 0; i < a; ++i) {
        int v;
        cin >> v;
        color[--v] = 0;
    }
    for (int i = 0; i < b; ++i) {
        int v;
        cin >> v;
        color[--v] = 1;
    }
    for (int i = 0; i < c; ++i) {
        int v;
        cin >> v;
        color[--v] = 2;
    }
    pref.resize(3, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            pref[j][i + 1] = pref[j][i];
        }
        ++pref[color[i]][i + 1];
    }
    best_score.resize(n + 1, INF);
    calc_best_score(0, n, 0, n);
    cout << *min_element(all(best_score)) << endl;
}