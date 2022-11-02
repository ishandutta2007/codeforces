#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXLEN = 20;
ll c[MAXLEN][MAXLEN];

void build() {
    for (int i = 0; i < MAXLEN; i++)
        c[i][0] = c[i][i] = 1;
    for (int i = 1; i < MAXLEN; i++) {
        for (int j = 1; j < MAXLEN; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }   
    }
    /*cout << "c = " << endl;
    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < MAXLEN; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }*/
}

ll n;

void read() {
    cin >> n;
}

ll ans;
int cnt[10];

ll get(vector<int> have) {
    ll fans = 1;
    int sum = 0;
    for (auto i : have) {
        sum += i;
    }
    for (auto i : have) {
        if (i == 0) continue;
        fans *= c[sum][i];
        sum -= i;
    }
    return fans;
}

void calc(vector<int> have) {
    bool flag = false;
    flag = have[0] > 0;
    if (!flag) {
        ans += get(have);
    } else {
        for (int i = 1; i < 10; i++) {
            if (!have[i]) continue;
            have[i]--;
            ans += get(have);
            have[i]++;
        }
    }
}

void solve(vector<int> have) {
    if (have.size() == 10) {
        calc(have);
        return;
    }
    have.push_back(0);
    if (cnt[have.size() - 1] == -1) {
        solve(have);
        return;
    }
    for (int i = 1; i <= cnt[have.size() - 1]; i++) {
        have[have.size() - 1]++;
        solve(have);
    }
}

void run() {
    while (n) {
        cnt[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i] == 0) {
            cnt[i] = -1;
        }
    }
    ans = 0;
    solve({});
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    build();
    read();
    run();
    write();
    return 0;
}