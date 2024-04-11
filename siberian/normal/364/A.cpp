#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int a;
string s;

void read() {
    cin >> a >> s;
}

vector<int> get_d(int a) {
    vector<int> ans;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            ans.push_back(i);
            ans.push_back(a / i);
        }
    }
    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());
    return ans;
}

ll ans;

const int MAXN = 4000 * 9 + 228;

int cnt[MAXN];

void run() {
    for (int i = 0; i < (int) s.size(); i++) {
        int sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += s[j] - '0';
            cnt[sum]++;
        }
    }

    if (a == 0) {
        int all = (int) s.size() * ((int) s.size() + 1) / 2;
        int zero = cnt[0];
        ans += (ll) all * zero * 2;
        ans -= (ll) zero * zero;
        return;
    }

    auto have = get_d(a);
    ans = 0;
    for (auto i : have) {
        if (i < MAXN && a / i < MAXN) {
            ans += (ll) cnt[i] * cnt[a / i];
        }
    }
}

void write() {
    cout << ans << endl;
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