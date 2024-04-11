#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Tree {
    vector <int> t;
    int n;
    Tree(vector <int> &a) {
        n = a.size();
        t.resize(2 * n, 0);
        for (int i = 0; i < n; i++) {
            t[i + n] = a[i];
        }
        for (int i = n - 1; i > 1; i--) {
            t[i] = min(t[2 * i], t[2 * i + 1]);
        }
    }
    int get(int l, int r) {
        int res = INF;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2) {
                res = min(res, t[l]);
            }
            if (r % 2 == 0) {
                res = min(res, t[r]);
            }
        }
        return res;
    }
};

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
    int n, q;
    cin >> n >> q;
    int bad = -1;
    vector <int> a(n);
    vector <int> l(q + 1, INF), r(q + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!a[i]) {
            a[i] = INF;
            bad = i;
        } else {
            l[a[i]] = min(l[a[i]], i);
            r[a[i]] = i;
        }
    }
    if (bad == -1 && l[q] == INF) {
        cout << "NO\n";
        return 0;
    }
    vector <int> st;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == INF) {
            if (last != -1) {
                a[i] = last;
            }
            continue;
        }
        last = a[i];
        if (!st.size()) {
            st.push_back(a[i]);
        } else if (st.back() > a[i]) {
            cout << "NO\n";
            return 0;
        } else if (st.back() < a[i]) {
            st.push_back(a[i]);
        }
        if (r[a[i]] == i) {
            st.pop_back();
        }
    }
    int now = 0;
    while (now < n && a[now] == INF) now++;
    if (now == n) {
        for (int &x : a) x = q;
    } else {
        for (int i = 0; i < now; i++) {
            a[i] = a[now];
        }
    }
    if (l[q] == INF) {
        a[bad] = q;
    }
    cout << "YES\n";
    for (int x : a) {
        cout << x << " ";
    }
}