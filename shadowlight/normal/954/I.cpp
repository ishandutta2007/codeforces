#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 2e5 + 7;
const double EPS = 1e-8;
const double PI = acos(-1);

struct Dsu {
    int n;
    vector <int> p, r;
    Dsu(int n) : n(n), p(n, 0), r(n, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int get(int v) {
        return (p[v] == v ? v : p[v] = get(p[v]));
    }
    bool uni(int v, int u) {
        v = get(v);
        u = get(u);
        if (v == u) {
            return false;
        }
        if (r[v] == r[u]) {
            r[u]++;
        }
        if (r[v] > r[u]) {
            swap(v, u);
        }
        p[v] = u;
        return true;
    }
};

int gr[MAXN][6][6];

int calc(int pos) {
    Dsu d(6);
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (!gr[pos][i][j]) continue;
            if (d.uni(i, j)) {
                cnt++;
            }
        }
    }
    return cnt;
}

typedef complex <double> cmpl;

inline int rev(int n, int k) {
    int res = 0;
    for (int i = 0; i < k; i++) {
        if (n & (1 << i)) {
            res += 1 << (k - i - 1);
        }
    }
    return res;
}

int sz, k;

inline void fft(cmpl *a, bool inv) {
    for (int i = 0; i < sz; i++) {
        int j = rev(i, k);
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    for (int l = 1; l < sz; l *= 2) {
        double alp = PI / l * (inv ? -1 : 1);
        cmpl wn = {cos(alp), sin(alp)};
        for (int i = 0; i < sz; i += 2 * l) {
            cmpl w = 1;
            for (int j = 0; j < l; j++) {
                cmpl y = a[i + j], z = a[i + j + l] * w;
                a[i + j] = y + z;
                a[i + j + l] = y - z;
                w *= wn;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < sz; i++) {
            a[i] /= sz;
        }
    }
}

inline void fft(cmpl *a, cmpl *b) {
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < sz; i++) {
        a[i] = a[i] * b[i];
    }
    fft(a, true);
}

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
    int n = s.size(), m = t.size();
    int len = 1;
    while (len <= n) {
        len *= 2;
    }
    //len *= 2;
    k = log2(len);
    sz = len;
    cmpl a[len], b[len];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == j) continue;
            for (int pos = 0; pos < len; pos++) {
                a[pos] = 0;
                b[pos] = 0;
            }
            for (int pos = 0; pos < n; pos++) {
                if (s[pos] - 'a' == i) {
                    a[pos] = 1;
                }
            }
            for (int pos = 0; pos < m; pos++) {
                if (t[pos] - 'a' == j) {
                    b[m - 1 - pos] = 1;
                }
            }
            fft(a, b);
            for (int pos = 0; pos <= n - m; pos++) {
                gr[pos][i][j] = round(a[pos + m - 1].real());
            }
        }
    }
    for (int i = 0; i < n - m + 1; i++) {
        cout << calc(i) << " ";
    }
}