#include <bits/stdc++.h>

using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return a * b % MOD;
}

int binpow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int x = binpow(a, n / 2);
        return mul(x, x);
    }
    else {
        int x = binpow(a, n - 1);
        return mul(x, a);
    }
}

int inv(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

int n, q;
vector<int> p;
set<int> have;

void read() {
    cin >> n >> q;
    have.insert(0);
    have.insert(n);
    p.resize(n);
    for (auto &i : p)
        cin >> i;
}

vector<int> pref;
vector<int> suff;

int ans = 0;

int get(int l, int r) {
    int ans = 0;
    ans = sub(pref[r], (l == 0 ? 0 : pref[l - 1]));
    ans = inv(ans, (r + 1 < n ? suff[r + 1] : 1));
    return ans;
}

void Add(int l, int r) {
    ans = add(ans, get(l, r));
}

void del(int l, int r) {
    ans = sub(ans, get(l, r));
}

int make(int x) {
    x = inv(100, x);
    return x;
}

void build() {
    for (int i = 0; i < n; i++)
        p[i] = make(p[i]);
    
    suff.resize(n);
    pref.resize(n);
    
    suff[n - 1] = p[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suff[i] = mul(suff[i + 1], p[i]);
    pref[0] = suff[0];

    for (int i = 1; i < n; i++)
        pref[i] = add(pref[i - 1], suff[i]);
    Add(0, n - 1);
}

int get(int pos) {
    if (have.count(pos)) {
        auto it = have.lower_bound(pos);
        --it;
        int l = *it;
        ++it;
        ++it;
        int r = *it;
        del(l, pos - 1);
        del(pos, r - 1);
        Add(l, r - 1);
        have.erase(pos);
    }
    else {
        auto it = have.lower_bound(pos);
        --it;
        int l = *it;
        ++it;
        int r = *it;
        del(l, r - 1);
        Add(l, pos - 1);
        Add(pos, r - 1);
        have.insert(pos);
    }
    return ans;
}

vector<int> fans;

void run() {
    build();
    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        u--;
        fans.push_back(get(u));
    }
}

void write() {
    for (auto i : fans)
        cout << i << "\n";
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