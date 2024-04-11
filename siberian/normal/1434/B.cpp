#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 1e5 + 10;
int n;

void read() {
    cin >> n;
}

void no() {
    cout << "NO\n";
    exit(0);
}

int ans[N];

vector<pair<vector<int>, int>> st;

void relax(int x) {
    while (!st.empty()) {
        if (st.back().first.empty()) {
            st.pop_back();
            continue;
        }
        if (st.back().second >= x) break;
        st[st.size() - 1].second = x;
        if (st.size() == 1) break;
        if (st[st.size() - 2].second >= x) break;
        if (st[st.size() - 2].first.size() < st[st.size() - 1].first.size()) {
            swap(st[st.size() - 1], st[st.size() - 2]);
        }
        for (auto i : st.back().first) {
            st[st.size() - 2].first.push_back(i);
        }
        st[st.size() - 2].second = x;
        st.pop_back();
    }
}

void run() {
    int cnt = 0;
    for (int i = 0; i < 2 * n; ++i) {
        char x;
        cin >> x;
        if (x == '+') {
            st.push_back({{cnt++}, 1});
        } else {
            int need;
            cin >> need;
            if (st.empty()) no();
            if (st.back().second > need) no();
            ans[st.back().first.back()] = need;
            st[st.size() - 1].first.pop_back();
            relax(need);
        }
    }
}

void write() {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}