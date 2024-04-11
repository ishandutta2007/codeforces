#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 2e3 + 10;
int n, m;
pair<int, int> a[N], b[N];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j].first >> b[j].second;
    }
}

const int D = 1e6 + 10;

vector<int> fRelax[D];
int suff[N];
int ptr[N];

int getD(int i, int dx) {
    while (ptr[i] < m && b[ptr[i]].first < a[i].first + dx) {
        ++ptr[i];
    }
    return suff[ptr[i]] - a[i].second + 1;
} 

int last[N];
int fans[D];
int posFans;

void build() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int d = b[j].first - a[i].first + 1;
            if (d < 0) continue;
            fRelax[d].push_back(i);
        }
    }
    
    sort(b, b + m);
    fill(suff, suff + N, -1);

    for (int i = m - 1; i >= 0; --i) {
        suff[i] = b[i].second;
        chkmax(suff[i], suff[i + 1]);
    }
    posFans = D - 1;
    for (int i = 0; i < n; ++i) {
        last[i] = getD(i, 0);
        if (last[i] >= 0) {
            ++fans[last[i]];
        }
    }
}

int getAns() {
    while (posFans > 0 && fans[posFans] == 0) {
        --posFans;
    }
    return posFans;
}

int ans;

void solve() {
    chkmin(ans, getAns());
    for (int d = 1; d < D; ++d) {
        for (auto i : fRelax[d]) {
            if (last[i] >= 0) {
                --fans[last[i]];
            }
            last[i] = getD(i, d);
            if (last[i] >= 0) {
                ++fans[last[i]];
            }    
        }
        chkmin(ans, getAns() + d);
    }
}

void run() {
    ans = D * 2;
    build();
    solve();
}

void write() {
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}