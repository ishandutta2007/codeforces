#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 110;
int n;
int p[N];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
}

vector<vector<int>> ans;

void upd(vector<int> have) {
    ans.push_back(have);
    /*cout << "have = " << endl;
    for (auto i : have) {
        cout << i << " ";
    }
    cout << endl;*/
    vector<vector<int>> a;
    int pos = 0;
    for (auto i : have) {
        a.push_back({});
        for (int j = 0; j < i; ++j) {
            a[a.size() - 1].push_back(p[pos]);
            ++pos;
        }
    }
    reverse(all(a));
    pos = 0;
    for (auto i : a) {
        for (auto j : i) {
            p[pos] = j;
            ++pos;
        }
    }
}

void make(int a, int b) {
    vector<int> have;
    if (a > 0) {
        have.push_back(a);
    }
    int pos = a;
    while (pos + 1 < b && p[pos + 1] == p[pos] + 1) {
        ++pos;
    }
    have.push_back(pos - a + 1);
    a = pos;
    have.push_back(b - a);
    if (b != n - 1) {
        have.push_back(n - 1 - b);
    }
    upd(have);
}

void run() {
    while (true) {
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (p[j] == p[i] + 1) {
                    make(j, i);
                    ok = true;
                    break;
                }
            }
        }
        /*cout << "p = " << endl;
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;*/
        if (!ok) break;
    }
    assert(ans.size() <= n);
    for (int i = 1; i < n; ++i) {
        assert(p[i] == p[i - 1] + 1);
    }
}

void write() {
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i.size();
        for (auto x : i) {
            cout << " " << x;
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}