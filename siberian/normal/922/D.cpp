#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n;
ll ans;
vector<pair<int, int>> a;

pair<int, int> readString() {
    string s;
    cin >> s;
    pair<int, int> fans;
    for (auto i : s) {
        fans.first += i == 's';
        fans.second += i == 'h';
    }
    int cnt = 0;
    for (auto i : s) {
        if (i == 'h') {
            ans += cnt;
        } else {
            ++cnt;
        }
    }
    return fans;
}

void read() {
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; ++i) {
        a.push_back(readString());
    }
}

void run() {
    sort(all(a), [&] (pair<int, int> i, pair<int, int> j) {
        return i.first * j.second > j.first * i.second;
    });
    int cnt = 0;
    for (auto i : a) {
        ans += (ll)i.second * cnt;
        cnt += i.first;
    }
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}