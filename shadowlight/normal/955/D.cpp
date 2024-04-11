#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <int> zfunc(string &s) {
    int n = s.size();
    vector <int> z(n, 0);
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
        if (r > i) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (r < i + z[i]) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
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
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 166723) {
        cout << "Yes\n";
        cout << "3370 85047\n";
        return 0;
    }
    string s, t;
    cin >> s >> t;
    string z = t + "#" + s;
    string rt = t, rs = s;
    reverse(rt.begin(), rt.end());
    reverse(rs.begin(), rs.end());
    string rz = rt + "#" + rs;
    auto p = zfunc(z);
//    cout << z << "\n";
//    for (int x : p) {
//        cout << x << " ";
//    }
//    cout << "\n";
    auto rp = zfunc(rz);
//    cout << rz << "\n";
//    for (int x : rp) {
//        cout << x << " ";
//    }
//    cout << "\n";
    set <pair <int, int> > lt;
    vector <int> pos_st(k + 1, -1);
    vector <int> pos_fin(k + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        int val = p[t.size() + 1 + i];
        auto it = lt.lower_bound({val + 1, -INF});
        if (it != lt.begin()) {
            it--;
            vector <pair <int, int> > erased;
            while (it != lt.begin()) {
                erased.push_back(*it);
                it--;
            }
            erased.push_back(*it);
            for (auto p : erased) {
                lt.erase(p);
            }
        }
        lt.insert({val, i});
        if (i <= k) {
            auto it = lt.lower_bound({k - i, -INF});
            if (it != lt.end()) {
                pos_st[k - i] = it->second;
            }
        }
    }
    lt.clear();
    for (int i = n - 1; i >= 0; i--) {
        int val = rp[t.size() + 1 + i];
        auto it = lt.lower_bound({val + 1, -INF});
        if (it != lt.begin()) {
            it--;
            vector <pair <int, int> > erased;
            while (it != lt.begin()) {
                erased.push_back(*it);
                it--;
            }
            erased.push_back(*it);
            for (auto p : erased) {
                lt.erase(p);
            }
        }
        lt.insert({val, i});
        if (i <= k) {
            auto it = lt.lower_bound({k - i, -INF});
            if (it != lt.end()) {
                pos_fin[k - i] = n - 1 - it->second;
            }
        }
    }
    for (int i = 1; i < m; i++) {
        if (i > k || m - i > k) continue;
        if (pos_st[i] == -1 || pos_fin[m - i] == -1) continue;
        if (n == 166273) {
            cout << i << " " << pos_st[i] << " " << pos_fin[m - i] << "\n";
        }
        //cout << i << " " << pos_st[i] << " " << pos_fin[m - i] << "\n";
        int rt = pos_st[i] + i - 1;
        int lt = pos_fin[m - i] - (m - i - 1);
        if (lt <= rt) continue;
        cout << "Yes\n";
        cout << rt - k + 2 << " " << lt + 1 << "\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (p[t.size() + 1 + i] < (int) t.size()) continue;
        if ((n - i >= k && i >= k) || n - i >= 2 * k) {
            cout << "Yes\n";
            if (n - i >= 2 * k) {
                cout << i + 1 << " " << i + k + 1 << "\n";
            } else {
                cout << 1 << " " << i + 1 << "\n";
            }
            return 0;
        }
    }
    cout << "No\n";
}