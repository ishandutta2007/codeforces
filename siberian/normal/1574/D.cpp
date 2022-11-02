#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 10;
int n;
int c[N];
vector<int> a[N];

const int MEM = 1e6 + 228;
int top = 1;
map<int, int> go[MEM];

void addVector(const vector<int>& v) {
    int now = 0;
    for (const auto& x : v) {
        if (go[now].find(x) == go[now].end()) {
            go[now][x] = top++;
        }
        now = go[now][x];
    }
}

int ans[N];
int sumAns = -1;
int fans[N];

void relax() {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i][fans[i]];
    }
    if (sum > sumAns) {
        sumAns = sum;
        for (int i = 0; i < n; ++i) {
            ans[i] = fans[i];
        }
    }
}

void relax(int cnt) {
    for (int i = cnt; i < n; ++i) {
        fans[i] = c[i] - 1;
    }
    relax();
}

void Go(int v, int cnt) {
    if (cnt == n) return;
    int prev = -1;
    for (auto [x, to] : go[v]) {
        if (x - 1 != prev) {
            fans[cnt] = x - 1;
            relax(cnt + 1);
        }
        prev = x;
        fans[cnt] = x;
        Go(to, cnt + 1);
    }
    if (go[v].find(c[cnt] - 1) == go[v].end()) {
        relax(cnt);   
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        a[i].resize(c[i]);
        for (auto& x : a[i]) {
            cin >> x;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        vector<int> v(n);
        for (auto& i : v) {
            cin >> i;
            --i;
        }
        addVector(v);
    }
    Go(0, 0);
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << ' ';
        cout << ans[i] + 1;
    }
    cout << endl;
    return 0;
}