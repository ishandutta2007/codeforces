#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<pair<int, int>> a;

void read() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        a.push_back({x, i});
    }
}

int fans = 0;
vector<int> ans;

void run() {
    sort(all(a));
    int cntL = 0, cntR = 0;
    int L = 0, R = 0;
    ans.resize(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        int j = i;
        while (j < 2 * n && a[i].first == a[j].first) {
            j++;
        }
        int have = j - i;
        if (have > 1) {
            ans[a[i].second] = 1;
            ans[a[i + 1].second] = 2;
            L++;
            R++;
            cntL++;
            cntR++;
        } else {
            if (L < R) {
                ans[a[j - 1].second] = 1;
                L++;
                cntL++;
            } else {
                ans[a[j - 1].second] = 2;
                R++;
                cntR++;
            }
        }
        i = j - 1;
    }
    for (auto i : a) {
        if (ans[i.second]) continue;
        if (cntL < cntR) {
            ans[i.second] = 1;
            cntL++;
        } else {
            ans[i.second] = 2;
            cntR++;
        }
    }
    //cout << L << " " << R << endl;
    assert(abs(L - R) <= 1);
    fans = L * R;
}

void write() {
    cout << fans << endl;
    for (auto i : ans) {
        cout << i << " "; 
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}